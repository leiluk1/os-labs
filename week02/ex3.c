#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void convert(long long x, int from, int to) {
    if (!((from >=2 && from <= 10) && (to >=2 && to <= 10))) {
        printf("cannot convert!\n");
        return;
    }
    long long dec = 0;
    int i = 0;
    while (x > 0) {
        int digit = x % 10;
        dec += digit * pow(from, i++);
        x /= 10;
    }
    char res[256];
    int l = 0;
    while (dec > 0) {
        char y = dec % to + '0';
        dec /= to;
        res[l] = y;
        l++; 
    }
    
    for (int i = l - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }
    printf("\n");
}


int main() {
    long long num;
    int from;
    int to;
    int input = scanf("%llu %d %d", &num, &from, &to);

    if (input == 3) {
        convert(num, from, to);
    }
    else {
        printf("cannot convert!");
    }
    
    return 0;
}