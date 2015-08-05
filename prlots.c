#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char S[1001],C[1001];
		scanf("%s",S);
		int count=0,i=0;
		while(S[i]!='\0')
		{
			count++;
			i++;
		}
		int val[count];
		for(i=0;i<count;i++)
		{
			scanf("%d",&val[i]);
			C[i]=S[val[i]-1];
		}
		C[i]='\0';
		printf("%s\n",C);

	}
	return 0;
}