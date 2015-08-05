#include<stdio.h>
int main()
{
	char S[1001];
	while(scanf("%s",S)!=EOF)
	{
		char ch,local;
		int i=1,count=0;
		while(S[i]!='\0')
		{
			ch=S[i-1];
			local=S[i];
			if((ch>=65&&ch<=90)&&(local>=65&&local<=90))
				count++;
			else if((ch>=90&&ch<=122)&&(local>=90&&local<=122))
				count++;
			i++;
		}
		printf("%d\n",count);
	}
	return 0;
}