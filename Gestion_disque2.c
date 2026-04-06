#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char** argv)
{
    DIR *directory;
    struct dirent *ent;
    struct stat st;
    char buffer[100];

    for(int i=1; i<argc; i++)
    {
        directory = opendir(argv[i]);
        if (directory == NULL)
        {
            printf("Erreur d'ouverture du répertoire %s\n", argv[i]);
            exit(1);
        }
        printf("==== Répertoire %s ====\n", argv[i]);
    
        while((ent = readdir(directory)) != NULL)
        {
            if (argv[i][strlen(argv[i])-1] == '/') sprintf(buffer, "%s%s", argv[i], ent->d_name);
            else sprintf(buffer, "%s/%s", argv[i], ent->d_name);
            if (stat(buffer, &st) != 0)
            {
                printf("Erreur d'accès au fichier\n");
                exit(1);
            }
            if (st.st_size >= 1000000)
            {
                printf("%d\t%s\n", st.st_uid, ent->d_name);
            }
        }
        printf("\n");
    }

    return 0;
}