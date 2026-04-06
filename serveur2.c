#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdbool.h>
#include<string.h>

int CreateSocket();
void printIpAndPort(int sock);
bool CheckClientIp(int sock);

int main()
{
    pid_t client_pid;
    int sockContact, sockClient, taille, i;
    struct sockaddr_in adress;
    socklen_t size = sizeof(struct sockaddr_in);

    sockContact = CreateSocket();

    if (sockContact < 0)
    {
        printf("Erreur de la création de socket\n");
        return -1;
    }

    listen(sockContact, 5);

    printf("Ip : ");
    printIpAndPort(sockContact);

    while(true)
    {
        sockClient = accept(sockContact, (struct sockaddr*)&adress, &size);

        if (sockClient < 0)
        {
            printf("Erreur accept\n");
            return -1;
        }

        client_pid = fork();

        if (client_pid == -1)
        {
            close(sockContact);
            printf("Erreur de la création de nouveau processus\n");
            return -1;
        }

        if (client_pid == 0)
        {
            close(sockContact);
            if (CheckClientIp(sockClient)) 
            {
                printf("Autorisé\n");
            }
            else
            {
                printf("Non Autorisé\n");
            }
            exit(0);
        }

        close(sockClient);
    }
    
    return 0;
}

int CreateSocket()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int opt;
    struct sockaddr_in adresse;
    socklen_t size = sizeof(struct sockaddr_in);

    if (sock < 0) 
    {
        printf("Erreur de la création de socket\n");
        return -1;
    }

    memset(&adresse, 0, sizeof(struct sockaddr_in));

    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(33333);
    inet_aton("127.0.0.1", &adresse.sin_addr);

    opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) 
    {
        printf("Erreur de setsockopt\n");
        exit(1);
    }

    if (bind(sock, (struct sockaddr*)&adresse, size) < 0)
    {
        printf("Erreur bind");
        close(sock);
        return -1;
    }
    
    return sock;
}

void printIpAndPort(int sock)
{
    struct sockaddr_in adresse;
    socklen_t longueur = sizeof(struct sockaddr_in);

    if (getsockname(sock, (struct sockaddr*)&adresse, &longueur) < 0)
    {
        close(sock);
        printf("Erreur de getsockname\n");
        exit (1);
    }

    printf("%s, PORT : %u\n", inet_ntoa(adresse.sin_addr), ntohs(adresse.sin_port));
}

bool CheckClientIp(int sock)
{
    FILE* file;
    struct sockaddr_in adresse;
    socklen_t size = sizeof(struct sockaddr_in);
    char buffer[20];

    file = fopen("add_autoris.txt", "r");

    if (file == NULL)
    {
        printf("Erreur d'ouverture de fichier\n");
        return -1;
    }

    if (getpeername(sock, (struct sockaddr*)&adresse, &size) < 0)
    {
        printf("Erreur de getpeername\n");
        return -1;
    }

    while(feof(file) != 1)
    {
        fscanf(file, "%s", buffer);
        if (strcmp(buffer, inet_ntoa(adresse.sin_addr)) == 0) return true;
    }
    fclose(file);
    return false;
}