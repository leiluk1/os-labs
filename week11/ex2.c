#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <dirent.h>
#include <sys/stat.h>


int main() {
    DIR *dir = opendir("/");
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        printf("%s ", entry->d_name);
    }
    printf("\n");
    closedir(dir);
    return 0;
}
