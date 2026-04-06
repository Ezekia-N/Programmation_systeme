#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define TAILLE 10

typedef struct TypeTableau
{
    int* tab;
    int NbreElement;
    int x;
} TypeTableau;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* ArrayAllocation(void* arg);
void* CheckXvalue(void* arg);

int main(void)
{
    pthread_t thread, check;
    TypeTableau* t;
    srand(time(NULL));
    int x, resultat;
    printf("Entrez la valeur de x : ");
    scanf("%d", &x);

    pthread_create(&thread, NULL, ArrayAllocation, (void*)10);
    pthread_join(thread, (void**)&t);
    t->x = x;

    for(int i = 0; i<TAILLE; i++)
    {
        printf("%d\n", t->tab[i]);
    }
    printf("x = %d\n", t->x);

    pthread_create(&check, NULL, CheckXvalue, (void*)&t);
    pthread_join(check, (void**)&resultat);
    printf("%d\n", resultat);
    return 0;
}

void* ArrayAllocation(void* arg)
{
    TypeTableau* T = malloc(sizeof(TypeTableau));
    T->NbreElement = (int)arg;
    T->tab = malloc(T->NbreElement*sizeof(int));

    pthread_mutex_lock(&m);
    for(int i=0; i<T->NbreElement; i++)
    {
        T->tab[i] = rand()%100;
    }
    pthread_mutex_unlock(&m);
    return (void*)T;
}

void* CheckXvalue(void* arg)
{    
    pthread_mutex_lock(&m);
    TypeTableau* T = (TypeTableau*)arg;
    for(int i = 0; i < T->NbreElement; i++)
    {
        if (T->tab[i] == T->x)
        {
            return (void*)1;
        }
    }
    pthread_mutex_unlock(&m);
    return (void*)0;
}