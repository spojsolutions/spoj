#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int N,U;
		scanf("%d%d",&N,&U);
		int A[N],T[N+1],val,low,high,i,count=0;
		for(i=0;i<=N;i++)
			T[i]=0;
		for(i=0;i<U;i++)
		{
			scanf("%d%d%d",&low,&high,&val);
			T[low]+=val;
			T[high+1]-=val;
		}
		for(i=0;i<N;i++)
		{
			count+=T[i];
			A[i]=count;
		}
		int Q,query;
		scanf("%d",&Q);
		for(i=0;i<Q;i++)
		{
			scanf("%d",&query);
			printf("%d\n",A[query]);
		}
	}
	return 0;
}