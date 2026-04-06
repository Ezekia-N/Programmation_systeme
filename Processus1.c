#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    __pid_t pid_fils = fork();

    if(pid_fils == -1)
    {
        printf("Erreur de création de nouveau processus\n");
        return 1;
    }
    if (pid_fils == 0)
    {
        printf("Je suis le fils\n");
    }
    else
    {
        printf("Je suis le père\n");
    }
    return 0;
}