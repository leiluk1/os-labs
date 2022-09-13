#include <stdio.h>

size_t tribonacci(int n) {
    size_t res = 0;
    size_t first = 0;
    size_t second = 1;
    size_t third = 1;
    if (n == 1 || n == 2) {
        res = 1;
    }
    for (int i = 3; i <= n; i++) {
        res = first + second + third;
        first = second;
        second = third;
        third = res;
    }
    return res;
}
int main() {
    printf("%lu\n", tribonacci(4));
    printf("%lu\n", tribonacci(36));
    return 0;
}