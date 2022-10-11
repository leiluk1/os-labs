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


void rr(process *procs, unsigned n, unsigned quantum) {
    qsort(procs, n, sizeof(process), (__compar_fn_t)comp);
    short *is_added = malloc(sizeof(short) * n),
          *is_completed = malloc(sizeof(int) * n);
    int *q = malloc(sizeof(int) * n), comp_count = 0, q_n = 0, t = procs[0].at;
    for (int i = 0; i < n; ++i) {
        is_added[i] = q[i] = 0;
        is_completed[i] = procs[i].bt;

        if (procs[i].at <= t) {
            is_added[i] = 1;
            q[q_n] = i;
            q_n++;
        }
    }
    while (1) {
        if (comp_count == n) {
            break;
        } 
        else if (q_n == 0) {
            for (int i = 0; i < n; i++) {
                if (is_added[i] == 0) {
                    t = procs[i].at;
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (procs[i].at <= t && is_added[i] == 0) {
                    q[q_n++] = i;
                }
            }
        }
        for (int i = 0; i < q_n; i++) {
            short is_finished = 0;
            if (quantum >= is_completed[q[i]]) {
                t += is_completed[q[i]];
                procs[q[i]].ct = t;
                comp_count++;
                is_finished = 1;
            } 
            else {
                t += quantum;
                is_completed[q[i]] -= quantum;
            }

            int new_count = 0;
            int *new_procs = malloc(sizeof(int) * n);
            for (int j = 0; j < n; j++) {
                if (procs[j].at <= t && is_added[j] == 0) {
                    new_procs[new_count] = j;
                    is_added[j] = 1;
                    new_count++;
                }
            }
            if (new_count > 0) {
                for (int j = q_n - 1; j >= i + is_finished; j--) {
                    q[j + new_count - is_finished] = q[j];
                }
                for (int j = 0; j < new_count; j++) {
                    q[i++] = new_procs[j];
                    q_n++;
                }
            } 
            else if (is_finished) {
                for (int j = i; j < q_n - 1; j++) {
                    q[j] = q[j + 1];
                }
            }
            if (is_finished) {
                q_n -= 1; i -= 1;
            }

            free(new_procs);
        }
    }

    free(is_completed);
    free(is_added);
    free(q);
}


int main() {
    int quantum;
    printf("Enter quantum:");
    scanf("%d", &quantum);

    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    process *procs = malloc(sizeof(process) * n);

    printf("Enter the AT and BT for the processes respectively:");
    for (int i = 0; i < n; i++) {
        scanf("%u %u", &procs[i].at, &procs[i].bt);
        procs[i].i = i;
    }
    rr(procs, n, quantum);

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