#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>


typedef struct {
	pthread_t id;
	int i;
	char message[256];
} Thread;

void *say_hello(void *t) {
	Thread thread = *(Thread *)t;
	printf("My id: %lu, message: %s\n", thread.id, thread.message);
	pthread_exit(EXIT_SUCCESS);

}

int main(){
	int n;
	printf("Enter n:\n");
	scanf("%d", &n);
	Thread* threads = malloc(n * sizeof(Thread));
	for (int i = 0; i < n; i++) {
		threads[i].i = i;
		sprintf(threads[i].message, "Hello from thread %d", i);
		printf("Thread %d is created\n", threads[i].i);
		pthread_create(&threads[i].id, NULL, say_hello, &threads[i]);
		pthread_join(threads[i].id, NULL);

	}

	free(threads);
	return EXIT_SUCCESS;
}
