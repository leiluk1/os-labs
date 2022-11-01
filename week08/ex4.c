#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>


int main() {
    int* a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(2621440 * sizeof(int));
        memset(a[i], 0, 2621440 * sizeof(int));
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory Usage: %ld\n", usage.ru_maxrss);
        sleep(1);
    }

    for (int i = 0; i < 10; i++) {
        free(a[i]);
    }
    return 0;
}