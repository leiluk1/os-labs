#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void count(char a[], char c) {
    int count = 0;
    char res[256];
    for (int i = 0; i < strlen(a); i++) {
        if (tolower(a[i]) == tolower(c)) {
            count++;
        }
    }
    printf("%c:%d", tolower(c), count);

}

void countAll(char b[]) {
    for (int j = 0; j < strlen(b); j++) {
        count(b, b[j]);
        if (j != strlen(b) - 1) {
            printf(", ");
        }
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        return 1;
    }
    countAll(argv[1]);
    return 0;
}