#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long N,t;
		scanf("%lld",&N);
		t=N/2;
		if(N%2==0)
			printf("%lld\n",((t-1)*(t-1))%N);
		else
			printf("%lld\n",(t*t)%N);
	}
	return 0;
}