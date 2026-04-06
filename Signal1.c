#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(void)
{
    __pid_t fils;
    fils = fork();
    char choix;

    switch (fils)
    {
        case -1:
        {
            printf("Erreur de la création de nouveau processus\n");
            return -1;
        }
        
        case 0:
        {   
            printf("fils : %d\n", getpid());
            while(1)
            {
                int c = 2+5;
            }
            break;
        }
        default:
        {
            printf("père : %d\n", getpid());
            do
            {
                printf("'s' pour endort le fils\n");
                printf("'r' pour redémare le fils\n");
                printf("'q' pour tue le fils\n");
                printf("choix : _");
                choix = getchar(); getchar();

                if (choix == 's')
                {
                    kill(fils, SIGSTOP);
                }
                else if(choix == 'r')
                {
                    kill(fils, SIGCONT);
                }
                else if(choix == 'q')
                {
                    kill(fils, SIGKILL);
                    break;
                }
            } 
            while (1);
            break;
        }
    }

    return 0;
}