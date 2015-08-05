#include<stdio.h>
#include<unistd.h>
int main()
{
	int ret=execl("/bin/ls","ls","-l","/home/nishant/history5oct.txt",NULL);
	if(ret==-1)
	{
		printf("execl error\n");
		return 0;
	}
	printf("success\n");
	return 0;
}