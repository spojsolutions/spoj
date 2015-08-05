#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int max;
		scanf("%d",&max);
		long long A[max];
		int i,flage=0;
		for(i=0;i<max;i++)
			scanf("%lld",&A[i]);
		for(i=0;i<max-1;i++)
		{
			if(A[i]>A[i+1])
				while(A[i+1]!=0)
				{
					A[i]=A[i]-1;
					A[i+1]=A[i+1]-1;
				}
			else
			{
				while(A[i]!=0)
			    {
					A[i+1]=A[i+1]-1;
					printf("%lld\n",A[i+1]);
					A[i]=A[i]-1;
			    }
			}
		}
		for(i=0;i<max;i++)
			if(A[i]!=0)
			{
				flage=1;
				break;
			}
		if(flage==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}