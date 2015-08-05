#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int a[n+5];
		int i,j,k,count=1;
		int res[210][210];
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			res[0][i]=i;
		}
		for(i=1;i<=n;i++)
		{
			count=1;
			j=i;
			while(a[j]!=i)
			{
				res[count++][i]=a[j];
				j=a[j];
			}
			res[209][i]=count;
		}
		while(1)
		{
			scanf("%d",&k);
			if(k==0)
				break;
			char *word;
			word=(char *)calloc(210,sizeof(char));
			char *final=(char *)calloc(210,sizeof(char));
			fflush(stdin);
			gets(word);
			int count,pos;
			for(i=1;i<=n;i++)
			{
				pos=res[k%res[209][i]][i];
				final[pos-1]=word[i]==0?32:word[i];
			}
			for(j=0;j<n;j++)
				printf("%c",final[j]);
				printf("\n");
		}
	}
	return 0;
}