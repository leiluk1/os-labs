#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    unsigned short int b = USHRT_MAX;
    signed long int c = LONG_MAX;
    float d = FLT_MAX;
    double e = DBL_MAX;

    printf("Size of integer: %ld\n", sizeof(a));
    printf("Size of unsigned short integer: %ld\n", sizeof(b));
    printf("Size of signed long integer: %ld\n", sizeof(c));
    printf("Size of float: %ld\n", sizeof(d));
    printf("Size of double: %ld\n", sizeof(e));
    printf("\n");

    printf("Maximum value of integer: %d\n", a);
    printf("Maximum value of unsigned short integer: %u\n", b);
    printf("Maximum value of signed long integer: %ld\n", c);
    printf("Maximum value of float: %f\n", d);
    printf("Maximum value of double: %f\n", e);
    return 0;
}