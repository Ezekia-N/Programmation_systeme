#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define TAILLE 10

void* ArrayAllocation(void* arg);

int main(void)
{
    pthread_t thread;
    srand(time(NULL));
    int* tab;
    pthread_create(&thread, NULL, ArrayAllocation, (void*)NULL);
    pthread_join(thread, (void**)&tab);

    for(int i = 0; i<TAILLE; i++)
    {
        printf("%d\n", tab[i]);
    }

    return 0;
}

void* ArrayAllocation(void* arg)
{
    int* tab = malloc(TAILLE*sizeof(int));
    for(int i=0; i<TAILLE; i++)
    {
        tab[i] = rand()%100;
    }
    return (void*)tab;
}