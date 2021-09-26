#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int waitstatus;
	int count = 0;
	pid = fork();
	if(0 < pid)
	{
		printf("I am the main thread :%d\n",getpid());
		wait(&waitstatus);
		printf("child is terminated\n");
	}
	else if(0 == pid)
	{
		while(count < 5)
		{
			printf("i am the child process :%d\n",getpid());
			count++;
			sleep(2);
		}
	}
	else
	{
		perror("fork creation failed:");
	}
	return 0;
}
