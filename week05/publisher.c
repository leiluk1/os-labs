#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("Publisher is here...\n");
    unsigned n = atoi(argv[1]);
    mkfifo("/tmp/ex1", 600);
    FILE *f = fopen("/tmp/ex1", "w");

    char* msg = NULL;
    size_t buf = 0;
    while (getline(&msg, &buf, stdin) != EOF) {
        for (unsigned i = 0; i < n; i++) {
            fprintf(f, "%s", msg);
            fflush(f);
            sleep(1);
        }
    }

    fclose(f);
    free(msg);
    return EXIT_SUCCESS;
}