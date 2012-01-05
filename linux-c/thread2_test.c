#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello world";

int run_row = 1;

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	char test[] = "Yu";
	int a = 0;
	int print_count1 = 0;

	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	while(print_count1++ < 20)
	{
		if(run_row == 1)
		{
			printf("1");
			run_row = 2;
		}
		else
		{
			sleep(1);
		}
	}

	printf("Waiting for thread to finish...\n");


	res = pthread_join(a_thread, &thread_result);

	if(res != 0)
	{
		perror("Thred join failed");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined, it returned %s\n", (char *)thread_result);

	printf("Message is now %s\n", message);
	exit(EXIT_SUCCESS);
}


void *thread_function(void *arg)
{
	int print_count2 = 0;
	
	while(print_count2++ < 20)
	{
		if(run_row == 2)
		{
			printf("2");
			run_row = 1;
		}
		else
		{
			sleep(1);
		}
	}
	printf("thread_function is running. Argument was %s\n", (char *)arg);
	sleep(3);
	strcpy((char *)arg, "Bye!");
	pthread_exit("Thank you for the CPU time");
}


