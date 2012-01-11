#include <stdio.h>
#include <signal.h>
#include <unistd.h>



void sig(int signum)
{
	printf("Received signal number %d!\n", signum);
}

int main(int argc, char *argv[])
{
	signal(SIGUSR1, sig);
	pause();

	return 0;
}


