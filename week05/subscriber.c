#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    printf("Subscriber is here...\n");
    FILE *f = fopen("/tmp/ex1", "r");
    char *msg = NULL;
    size_t buf = 0;
    while (getline(&msg, &buf, f) != EOF) {
        printf("recieved message: %s", msg);
    }
    free(msg);
    fclose(f);
    return EXIT_SUCCESS;
}