#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char fichier[20];
    printf("Entrez ici le nom du fichier : ");
    scanf("%s", fichier);

    char* argv[] = {"emacs", fichier, NULL};
    execv("/usr/bin/emacs", argv);

    return 0;
}