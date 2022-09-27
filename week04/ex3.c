#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv){

	int n = strtol(argv[1], NULL, 10);
	for (int i = 0; i < n; i++) {
		fork();
		sleep(5);
	}

	return EXIT_SUCCESS;

}
