#include<stdio.h>
#include<signal.h>
void sighandler(int signum)
{
	int i;
	for(i=0;i<10000;i++)
		printf("SIGINT recieved inside signalhandler\n\n\n");
}
int main()
{
	signal(SIGINT,sighandler);
	while(1){
		printf("Program running \n");}
	return 0;
}