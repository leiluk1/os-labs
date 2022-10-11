#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int i;
    int at;
    int bt;
    int ct;

} process;


int comp(const void *proc1, const void *proc2) {
    process *p1 = (process *)proc1;
    process *p2 = (process *)proc2;

    if (p1->at <= p2->at) {
        return -1;
    } else {
        return 1;
    }

}


void fcfs(process *procs, int n) {
    qsort(procs, n, sizeof(process), comp);
    int cur_time = 0;
    for (int i = 0; i < n; ++i) {
        process *p = &procs[i];
        if (p->at > cur_time) {
            cur_time = p->at;
        }

        cur_time += p->bt;
        p->ct = cur_time;
    }
}


int main() {
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    process *procs = malloc(sizeof(process) * n);

    printf("Enter the AT and BT for the processes respectively:");
    for (int i = 0; i < n; i++) {
        scanf("%u %u", &procs[i].at, &procs[i].bt);
        procs[i].i = i;
    }
    fcfs(procs, n);

    double sum_tat = 0;
    double sum_wat = 0;
    for (int i = 0; i < n; i++) {
        int tat = procs[i].ct - procs[i].at;
        int wat = procs[i].ct - procs[i].at - procs[i].bt;
        sum_tat += tat;
        sum_wat += wat;
        printf("P%03d: AT: %3d; BT: %3d; CT: %3d, TAT %3d, WAT: %3d\n",
               procs[i].i + 1, procs[i].at, procs[i].bt, procs[i].ct, tat, wat);
    }
    
    double avg_tat = sum_tat / n;
    double avg_wat = sum_wat / n;
    printf("Average TAT: %f\n", avg_tat);
    printf("Average WAT: %f\n", avg_wat);

    free(procs);
    return EXIT_SUCCESS;
}
