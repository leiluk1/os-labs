#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *realloc_func(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    else {
        if (size == 0) {
            free(ptr);
            return NULL;
        }
        else {
            void *updated_ptr = malloc(size);
            memcpy(updated_ptr, ptr, size);
            free(ptr);
            return updated_ptr;
        }
    }
}

int main() {
    int* ptr = realloc_func(NULL, 10 * sizeof(int));
    for (int i = 0; i < 10; i ++) {
        ptr[i] = i;
        printf("%d ", ptr[i]);
    }
    printf("\n");

    ptr = realloc_func(ptr, 5 * sizeof(int));
    for (int i = 0; i < 5; i ++) {
        // ptr[i] = i;
        printf("%d ", ptr[i]);
    }
    printf("\n");

    ptr = realloc_func(ptr, 15 * sizeof(int));
    for (int i = 0; i < 15; i ++) {
        ptr[i] = i >= 5 ? 0 : ptr[i];
        printf("%d ", ptr[i]);
    }
    printf("\n");

    ptr = realloc_func(ptr, 0);
    printf("%ls\n", ptr);
    return 0;
}