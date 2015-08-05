#include<stdio.h>
int main()
{
    int t=100;
	while(t--)
	{
		long long int n,sum=0;
		scanf("%lld",&n);
		if(n==EOF)
			break;
		sum=81+((n/9)-1)*81+(n%9)*(n%9);
		printf("%lld\n",sum);
	}
	return 0;
}

