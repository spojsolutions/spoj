#include<stdio.h>
#include<malloc.h>
int main()
{
	char s[40];
	int *count,N,i,flage=0;
	count=malloc(27*sizeof(int));
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%s",s);
		count[(s[0]-97)]++;
	}
	for(i=0;i<26;i++)
		if(count[i]>=5){
			flage=1;
			printf("%c",i+97);
		}
	if(flage==0)
		printf("PREDAJA");
	printf("\n");

	return 0;
}