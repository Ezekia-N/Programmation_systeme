#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char** argv)
{
    char* pwd = getenv("PWD");

    if (argc != 2)
    {
        printf("Usage : %s <chemin de destination>\n", argv[0]);
        return -1;
    }

    execl("/usr/bin/cp", "cp", "-rf", pwd, argv[1], NULL);

    return 0;
}