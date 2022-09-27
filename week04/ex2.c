#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int dotprod(int u[], int v[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += u[i] * v[i];
    }
    return result;
}

int main(void) {
    FILE *textfile = fopen("temp.txt", "w");
    srand(time(NULL));

    int size = 120, range = 100;
    int *u = malloc(sizeof(int) * size);
    int *v = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        u[i] = (rand() % range);
        v[i] = (rand() % range);
    }

    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int elem_per_process = size / n;
    pid_t *processes = malloc(n * sizeof(pid_t));

    int *u_tmp = u, *v_tmp = v;
    for (int i = 0; i < n; i++) {
        processes[i] = fork();

        if (processes[i] == 0) {
            fprintf(textfile, "%d\n", dotprod(u_tmp, v_tmp, elem_per_process));
            exit(EXIT_SUCCESS);
        }
        u_tmp += elem_per_process;
        v_tmp += elem_per_process;
    }
    fclose(textfile);

    while (wait(NULL) > 0);

    textfile = fopen("temp.txt", "r");
    int res = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        fscanf(textfile, "%d\n", &tmp);
        res += tmp;
    }

    printf("\nVector u:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", u[i]);
    }
    printf("\nVector v:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }

    printf("\nThe result of u * v: %d\n", res);

    fclose(textfile);
    free(processes);
    free(u);
    free(v);
    return EXIT_SUCCESS;
}