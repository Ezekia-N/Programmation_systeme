#include<stdio.h>
#include<stdlib.h>

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char** argv)
{   
    int nbre1, nbre2;

    if (argc < 3)
    {   
        printf("Usage : %s <nombre 1> <nombre 2>\n", argv[0]);
        return -1;
    }

    nbre1 = atoi(argv[1]);
    nbre2 = atoi(argv[2]);

    printf("Somme = %d\n", add(nbre1, nbre2));

    return 0;
}