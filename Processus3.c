#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    __pid_t pid_fils;

    for(int i=1; i<=5; i++)
    {
        pid_fils = fork();
        if (pid_fils == -1)
        {
            printf("Erreur de création de nouveau processus\n");
            return 1;
        }
        if(pid_fils == 0)
        {
            printf("Je suis le fils%d\n", i);
            break;
        }
        printf("Je suis le père\n");
    }

    return 0;
}