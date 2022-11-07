#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *file = fopen("input.txt", "r");
    int pages_number;
    printf("Input number of page frames: ");
    scanf("%d", &pages_number);

    int *table_pages = malloc(sizeof(int) * pages_number);
    int *counts = malloc(sizeof(int) * pages_number);
    short *table_rbits = malloc(sizeof(short) * pages_number);

    int page;
    int sz = 0, hits = 0, misses = 0;
    while (fscanf(file, "%d", &page) != EOF) {
        short flag = 0;
        int table_i;
        for (int i = 0; i < sz; i++) {
            if (table_pages[i] == page) {
                table_i = i;
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            hits++;
            table_rbits[table_i] = 1;

        } else {
            misses++;
            if (sz >= pages_number) {
                int table_j = 0;
                for (int i = 0; i < pages_number; i++) {
                    if (counts[i] < counts[table_j]) {
                        table_j = i;
                    }
                }

                table_rbits[table_j] = 1;
                counts[table_j] = 0;
                table_pages[table_j] = page;

            } else {
                table_rbits[sz] = 1;
                counts[sz] = 0;
                table_pages[sz] = page;
                sz++;
            }
        }

        for (int i = 0; i < sz; i++) {
            counts[i] = counts[i] >> 1;
            if (table_rbits[i] == 1) {
                counts[i] = counts[i] >> 1 | 0b10000000;
            }

            table_rbits[i] = 0;
        }
    }

    printf("Hits: %d\nMisses: %d\nRatio: %f\n", hits, misses, (double)hits / misses);

    free(table_pages);
    free(counts);
    free(table_rbits);
    fclose(file);

    return 0;
}
