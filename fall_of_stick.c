#include<stdio.h>
#include<math.h>
int main()
{
	while(1)
	{
		long long int n,sum=0;
		scanf("%lld",&n);
		if(n==EOF)
			break;
		if(n<=9)
			sum=pow(n,2);
		else
		{
			sum=72+n;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
