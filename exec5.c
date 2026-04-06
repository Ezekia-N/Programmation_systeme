#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    char fichier[50];
    __pid_t fils;

    while(true)
    {
        printf("Entrez ici le nom du fichier ou entrez q pour quitter : ");
        scanf("%s", fichier);

        if (strcmp(fichier, "q") == 0) break;

        fils = fork();
        if (fils == -1)
        {
            printf("Erreur de création de nouveau processus\n");
            return -1;
        }
        if (fils == 0)
        {
            execl("/usr/bin/emacs", "emacs", fichier, NULL);
        }
    }
    return 0;
}