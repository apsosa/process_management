#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(0 < pid)
	{
		while(1)
		{
			printf("I am the parent.Process ID:%d\n",getpid());
			sleep(5);
		}
	}
	else if(0 == pid)
	{
		while(1)
		{
			printf("I am the child process. Process ID:%d Parent ID:%d\n",getpid(),getppid());
			sleep(1);
		}
	}
	else
	{
		perror("fork creation failed :");
	}
	return 0;
}
