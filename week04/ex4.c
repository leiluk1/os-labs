#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void) {
    while (1) {
        char *str = NULL;
        size_t len = 0, n = 0;
        printf("Enter your command: ");
        n = getline(&str, &len, stdin);
        if (n > 0) {
            if (strncmp(str + n - 2, "&\n", 2) == 0) {
                *(str + n - 2) = '\0';
                pid_t child = fork();
                if (child == 0) {
                    system(str);
                    exit(EXIT_SUCCESS);
                }
            } else {
                system(str);
            }
        }
    }
    return EXIT_SUCCESS;
}




