#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(int age){
	int result;
	result = 2022 - age;
	return result;
}

int main(){
	const int x = 10;
	int *q = &x;
	const int *const p = (const int *const)malloc(5 *sizeof(int));
	memset(p, x, 5);

	printf("Memory addresses of the cells are the following:\n");

	for (int i = 0; i < 5; i++) {
		printf("%p\n", p + i);
	}

	printf("Enter the ages of students:\n");
	int *ages = p;
	for (int i = 0; i < 5; i++) {
		scanf("%d", ages + i);
	}
	for (int i = 0; i < 5; i++) {
		*(ages + i) = foo(*(ages + i));
		printf("The birth year of %d student is %d\n", i + 1, *(ages + i));
	}

	free(p);

	return EXIT_SUCCESS;
}
