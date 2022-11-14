#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <dirent.h>
#include <sys/stat.h>


int main() {
    chdir("./tmp");
    DIR *dir = opendir(".");
    struct dirent *entry;
    char **names = NULL;
    ino_t *inodes = NULL;
    int size = 0;


    while ((entry = readdir(dir)) != NULL) {
        struct stat buf;
        lstat(entry->d_name, &buf);

        if (buf.st_nlink > 1 && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            size++;
            names = realloc(names, (size * sizeof(char*)));
            names[size - 1] = strdup(entry->d_name);
            inodes = realloc(inodes, (size * sizeof(ino_t)));
            inodes[size - 1] = buf.st_ino;
        }   
    }
    closedir(dir);
    printf("File  ---- Hard Links\n");
    for (int i = 0; i < size; i++) {
        printf("%s ---- ", names[i]);
        for (int j = 0; j < size; j++) {
            if (inodes[i] == inodes[j]) {
                printf("%s ", names[j]);
            }
        }
        printf("\n");
    }
    
    for (int i = 0; i < size; i++) {
        free(names[i]);
    }
    free(names);
    free(inodes);
    return 0;
}