#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    char repertoire[50];
    char* pwd = getenv("PWD");
    __pid_t fils;

    while(true)
    {
        printf("Entrez ici le chemin de destination ou entrez (q) pour quitter : ");
        scanf("%s", repertoire);
        if (strcmp(repertoire, "q") == 0) break;
        fils = fork();
        if (fils == -1)
        {
            printf("Erreur de création de nouveau processus\n");
            return -1;
        }
        if (fils == 0)
        {
            execl("/usr/bin/cp", "cp", "-rf", pwd, repertoire, NULL);
        }
    }
    return 0;
}