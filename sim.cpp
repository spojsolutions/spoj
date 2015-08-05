#include<stdio.h>
#include<algorithm>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int N,K;
		scanf("%d%d",&N,&K);
		long int TOTAL[N];
		int i,j;
		for(i=0;i<N;i++)
			scanf("%ld",&TOTAL[i]);
		std::sort(TOTAL,TOTAL+N-1);
		long int DIFF[N-K+1];
		for(i=0,j=K-1;i<(N-K+1);i++,j++)
		{
			DIFF[i]=TOTAL[i]-TOTAL[j];
		}
		std::sort(DIFF,DIFF+N-K);
		printf("%ld\n",DIFF[N-K]);
	}
	return 0;
}