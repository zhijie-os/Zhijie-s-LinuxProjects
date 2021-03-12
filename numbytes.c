#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int size = 0;
    char buffer[100];
    system("./numbytes.sh > temp.dat");
    FILE *fp;
    fp = fopen("temp.dat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open temp.dat!\n");
    }
    if (fgets(buffer, 100, fp) != NULL)
    {
        char *token = strtok(buffer, ":");
        token = (char *)strtok(NULL,":");
        printf("%s",token);
    }
}