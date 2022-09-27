#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void print_res(int process_num, clock_t start_time) {
	double execution_time = (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000;
	printf("The ID of process #%d: %d, the ID of its parent: %d, the execution time: %f millisecons\n", 
		process_num, getpid(), getppid(), execution_time);
}

int main(void){
	pid_t child_a, child_b;
	clock_t start_time_a, start_time_b, start_time_p;
	start_time_p = clock();
	child_a = fork();
	start_time_a = clock();
	if (child_a == 0) {
    	print_res(1, start_time_a);
	} else {
    	child_b = fork();
		start_time_b = clock();
    	if (child_b == 0) {
        	print_res(2, start_time_b);
    	} else {
			print_res(3, start_time_p);
    	}
	}
	return EXIT_SUCCESS;

}
