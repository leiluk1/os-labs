#include <stdio.h>
#include <string.h>

int main() {
    char a[256];
    char cur;
    printf("Enter the string:");
    cur = getchar();
    while (cur != '.' && cur != '\n') {
        strcat(a, &cur);
        cur = getchar();
    }
    printf("\"");
    for (int i = strlen(a) - 1; i > 0; i--) {
        printf("%c", a[i]);
    }
    printf("\"");
    return 0;
}