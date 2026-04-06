#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    __pid_t pid_fils1, pid_fils2;
    pid_fils1 = fork();
    if (pid_fils1 == -1)
    {
        printf("Erreur de création de nouveau processus\n");
        return 1;
    }
    if (pid_fils1 == 0)
    {
        printf("Je suis le fils1\n");    
    }
    else
    {
        printf("Je suis le père\n");

        pid_fils2 = fork();
        
        if (pid_fils2 == -1)
        {
            printf("Erreur de création de nouveau processus\n");
            return 1;
        }
        if (pid_fils2 == 0)
        {
            printf("Je suis le fils2\n");
        }
    }
    return 0;
}