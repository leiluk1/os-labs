// Exercise 2
//
// Since I have 12GB RAM, 10MB of memory is too few to occupy all physical
// memory. Therefore, no pages are swapped to the disk. Thus, "si" and "so"
// fields are filled with zeros. 

// Exercise 3
//
// When we run top command, we can notice that our process is on the top of the
// list. Moreover, the value in Memory Usage ("RES") field is increasing
// significantly each second, because the allocations happen.


#include <malloc.h>
#include <string.h>
#include <unistd.h>


int main() {
    int* a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(2621440 * sizeof(int));
        memset(a[i], 0, 2621440 * sizeof(int));
        sleep(1);
    }

    for (int i = 0; i < 10; i++) {
        free(a[i]);
    }
    return 0;
}