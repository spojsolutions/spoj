#include<stdio.h>
int main()
{
	char S[100009];
	int i;
	while(scanf("%s",S)!=EOF)
	{
		int count=1,i=1,k=0;
		while(S[i]!='\0')
		{
			if(S[i-1]==S[i])
				count++;
			else
			{
				if(count>3)
				{
					printf("%d!%c",count,S[i-1]);
				}
				else
					for(k=0;k<count;k++)
						printf("%c",S[i-1]);
				i++;
				count=1;
				continue;
			}
			i++;
		}
		if(count<=3)
			for(k=0;k<count;k++)
				printf("%c",S[i-1]);
		else
			printf("%d!%c",count,S[i-1]);
		printf("\n");
	}
	return 0;
}