#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello world";

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	char test[] = "Yu";
	int a = 0;

	res = pthread_create(&a_thread, NULL, thread_function, (void *)&a);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish...\n");

	res = pthread_join(a_thread, &thread_result);

	if(res != 0)
	{
		perror("Thred join failed");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined, it returned %d\n", *(int *)thread_result);

	printf("Message is now %d\n", a);
	exit(EXIT_SUCCESS);
}


void *thread_function(void *arg)
{
	printf("thread_function is running. Argument was %d\n", *(int *)arg);
	sleep(3);
	*(int *)arg = 1;
	//strcpy((char *)arg, "Bye!");
	pthread_exit(arg);
}


