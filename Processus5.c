#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>

int main(void)
{
    __pid_t pid_fils1, pid_fils2;
    int nbre_seconde;
    srand(time(NULL));
    time_t t1 = time(NULL);

    nbre_seconde = (rand()%10)+1;

    pid_fils1 = fork();
    
    if (pid_fils1 == -1)
    {
        printf("Erreur de création de nouveau processus\n");
        return 1;
    }

    if (pid_fils1 == 0)
    {
        sleep(nbre_seconde);
    }
    else
    {
        pid_fils2 = fork();
        if (pid_fils2 == -1)
        {
            printf("Erreur de création de nouveau processus\n");
            return 1;
        }
        if (pid_fils2 == 0)
        {
            sleep(nbre_seconde);
        }
        else
        {
            waitpid(pid_fils1, NULL, 0);
            waitpid(pid_fils2, NULL, 0);
            printf("La durrée totale : %ld\n", time(NULL)-t1);
        }
    }
    return 0;
}