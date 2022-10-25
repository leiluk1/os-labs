#include <stdlib.h>
#include <stdio.h>

int main() {
    int N = 0;
    printf("Enter N: ");
    scanf("%d", &N);

    int *a = (int *)calloc(N, sizeof(int));
    
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }
    printf("a = [");
    for (int i = 0; i < N - 1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d]", a[N - 1]);

    free(a);
    return 0;
}