#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s;
    char foo[] = "Hello World";
    // *s = foo;
    // this line generates a segmetation fault, since we had not initialized value of s and we try to access it 
    s = (char**)malloc(sizeof(char**));
    *s = foo;
    printf ("s is %s\n", s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]) ;
    return (0) ;
}
