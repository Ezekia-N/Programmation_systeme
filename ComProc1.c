#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(void)
{
    FILE *fp;
    __pid_t pid_fils;
    int fd1[2], fd2[2];

    if (pipe(fd1) != 0)
    {
        printf("Erreur sur la création du pipe1\n");
        return 1;
    }

    if (pipe(fd2) != 0)
    {
        printf("Erreur sur la création du pipe1\n");
        return 1;
    }

    pid_fils = fork();

    switch (pid_fils)
    {
        case -1:
        {
            printf("Erreur de la création de nouveau processus\n");
            return 1;
            break;
        }

        case 0:
        {
            char bufferW[50];
            int resultatR;

            close(fd2[1]);
            close(fd1[0]);

            printf("Entrez le mot à rechercher : ");
            scanf("%s", bufferW);
            write(fd1[1], bufferW, sizeof(bufferW));
            read(fd2[0], &resultatR, sizeof(int));
            printf("Résultat de recherche : %d\n", resultatR);

            close(fd1[1]);
            close(fd2[0]);
        }

        default:
        {
            char bufferR[50], buffer[50];
            int resultatW = 0;

            close(fd1[1]);
            close(fd2[0]);

            read(fd1[0], bufferR, sizeof(bufferR));

            fp = fopen("fichier.txt", "r");

            if (fp == NULL)
            {
                printf("Erreur d'ouverture de fichier\n");
                return 1;
            }

            while(feof(fp) != 1)
            {
                fscanf(fp, "%s", buffer);
                if (strcmp(buffer, bufferR) == 0)
                {
                    resultatW = 1;
                    break;
                }
            }
            write(fd2[1], &resultatW, sizeof(int));
            fclose(fp);
            break;
        }
    }

    return 0;
}