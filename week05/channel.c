#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t subscriber = fork();
    if (subscriber == 0) {
        close(fd[0]);
        char *msg = malloc(1024 * sizeof(char));
        size_t buf = 1024;
        int n;
        while ((n = getline(&msg, &buf, stdin)) != EOF) {
            write(fd[1], msg, n);
            free(msg);
            msg = malloc(1024 * sizeof(char));
        }
        close(fd[1]);
        free(msg);
    } else {
        close(fd[1]);
        char msg[1024];
        while (read(fd[0], msg, 1024) != EOF) {
            printf("recieved message: %s", msg);
            memset(msg, 0, strlen(msg));
        }
        close(fd[0]);
    }
    return EXIT_SUCCESS;
}