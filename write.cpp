#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	FILE *fp;
	char buffer[10000];
	strcpy(buffer , "hello\n");
	fp = popen("wc","w");
	printf("process %d Tx -> %s\n",getpid(),buffer);
	fwrite(buffer,sizeof(char),strlen(buffer),fp);
	pclose(fp);
	return 0;
}
