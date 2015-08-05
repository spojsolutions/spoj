#include <stdio.h>
#include <inttypes.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long x,n,r;
		scanf("%llu%llu",&x,&n);
		r=x + (x-n)/(n-1) + 1;
		printf("%llu\n", r);
	}
	return 0;
}