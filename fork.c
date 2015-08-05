#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int PID;
	PID=fork();
	if(PID==0)
	{
		printf("I am child process\n");
		printf("Child:child's PID:=%d\n",getpid());
		printf("child:parent's PID:=%d\n",getppid());
	}
	else
	{
		printf("Parent process running\n");
		printf("parent:parent's PID%d\n",getpid());
		printf("parent:Child's PID%d\n",PID);
	}
	return 0;
}