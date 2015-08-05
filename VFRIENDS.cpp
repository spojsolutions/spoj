#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
	int t;
	scanf("%d".&t);
	while(t--)
	{
		int n,i,j;
		scanf("%d",&n);
		int a[n+9];
		int *sum=(int *)calloc(n+9,sizeof(int));
		int temp=n,flag=1;
		long long s=0,count=0,ksum=0;
		for(i=n;i>=1;i--)
		{
			scanf("%d",&a[i]);
			s=s+a[i];
		}
		if(s%2==0)
		{
			sum[0]=0;
			flag=1;
			for(i=1;i<=n;i++)
				sum[i]=sum[i-1]+a[i];
			for(i=1;i<=n;i++)
			{
				ksum=0;
				for(j=i+1;j<=n;j++)
					ksum+=min(a[j],i);
				if( sum[i] > (i*(i-1) + ksum))
				{
					flag=0;
					break;
				}
			}
			if(flag)
				printf("HAPPY\n");
			else
				printf("SAD\n");
		}
		else
			printf("SAD\n");
	}
	return 0;
}