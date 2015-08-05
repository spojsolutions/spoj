#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,n;
		scanf("%d",&n);
		int *degree=(int *)calloc(309,sizeof(int ));
		int max=-1,flag=0,temp;
		while(1)
		{
			scanf("%d%d",&i,&j);
			if(i==-1 && j==-1)
				break;
			degree[i]++;
			degree[j]++;
			temp=i<j?j:i;
			max<temp?max=temp:max=max;
		}
		for(int i=1;i<=max;i++)
			if(degree[i]%2!=0)
			{
				flag=1;
				break;
			}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}