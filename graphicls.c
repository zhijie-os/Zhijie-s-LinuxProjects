#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void listDir(const char *dirname, int level)
{
    //  Open directory and assign to DIR pointer
    DIR *dir = opendir(dirname);

    //  if dir is null => cannot open the directory
    if (dir == NULL)
    {
        printf("Cannot open dir");
    }

    struct stat fileStat;
    struct dirent *entity;

    //read next file from current directory.
    entity = readdir(dir);


    //keep reading next file until there is no file.
    while (entity != NULL)
    {
        // ignore "." and ".."
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0)
        {
            // if current file is a directory, print "----" before.
            if (entity->d_type == DT_DIR)
            {
                for (int i = 0; i < level; i++)
                {
                    printf("----");
                }
            } // otherwise, print "    "
            else
            {
                for (int i = 0; i < level; i++)
                {
                    printf("    ");
                }
            }
            char buffer[120] = "";
            // print the file name
            printf("|%s", entity->d_name);
            switch (entity->d_type)
            {
            case DT_DIR:
                printf("(directory )");
                break;
            case DT_LNK:
                printf("(symlink)");
                break;
            case DT_REG:

                //stat(entity->d_name, &fileStat);

                printf("(regular file)");
                break;
            default:
                printf("(unknow!)");
                break;
            }
            printf("\n");
            // if entity is directory, enter to next level and ls recursively
            if (entity->d_type == DT_DIR)
            {
                // concatenate the file path
                char nextPath[256] = "";
                strcat(nextPath, dirname);
                strcat(nextPath, "/");
                strcat(nextPath, entity->d_name);
                listDir(nextPath, level + 1);
            }
        }
        // read next file
        entity = readdir(dir);
    }
    //close the dir
    closedir(dir);
}

int main(int argc, char *args[])
{
    listDir(args[1], 0);
}