#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define TAILLE 10

void* printArray(void* arg);

int main(void)
{
    pthread_t thread;
    int tab[TAILLE] = {1,2,3,4,5,6,7,8,9,10};
    pthread_create(&thread, NULL, printArray, tab);
    pthread_join(thread, NULL);
    return 0;
}

void* printArray(void* arg)
{
    int *tab = (int*)arg;
    for(int i=0; i<TAILLE; i++)
    {
        printf("%d\n", tab[i]);
    }
    pthread_exit(NULL);
}