#include<stdio.h>
int main()
{
	while(1)
	{
		int N;
		scanf("%d",&N);
		if(N==-1)
			break;
		int A[N+1],i;
		long long sum=0,count=0,avg;
		for(i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			sum=sum+A[i];
		}
		if(sum%N!=0)
			printf("-1\n");
		else
		{
			avg=sum/N;
			for(i=0;i<N;i++)
			{
				if(A[i]>avg)
					count+=(A[i]-avg);
			}
			printf("%lld\n",count);
		}
	}
	return 0;
}