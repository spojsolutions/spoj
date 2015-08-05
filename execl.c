#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		execl("/bin/ls","-al","/etc",NULL);
		printf("Child:After execl()\n");
	}
	else
		printf("Parent Process\n");
	return 0;
}