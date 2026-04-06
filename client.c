#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int CreateSocket(int argc, char** argv);

int main(int argc, char** argv)
{
    int sock;

    if (argc != 3)
    {
        printf("Usage : <%s> <adresse> <port>\n", argv[0]);
        return 1;
    }

    sock = CreateSocket(argc, argv);
    if(sock < 0)
    {
        printf("Erreur de la création de socket\n");
        return -1;
    }

    printf("On est connecté\n");
}

int CreateSocket(int argc, char** argv)
{
    int sock;
    struct sockaddr_in adresse;
    socklen_t size = sizeof(struct sockaddr_in);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Erreur socket\n");
        return -1;
    }
    memset(&adresse, 0, size);
    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &adresse.sin_addr);

    if (connect(sock, (struct sockaddr*)&adresse, size) < 0)
    {
        printf("Erreur connect\n");
        return -1;
    }

    return sock;
}