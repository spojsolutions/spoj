#include<stdio.h>
int main()
{
	int t,n=1;
	scanf("%d",&t);
	while(n<=t)
	{
		long long result1;
		double i,j,k,a,b,c;
		scanf("%lf%lf%lf",&i,&j,&k);
		result1=(i*j*k)-1;
		a=i;b=j;c=k;
		int l=0;
		while(a>1)
		{
			a=a/2;
			l++;
		}
		while(b>1)
		{
			b=b/2;
			l++;
		}
		while(c>1)
		{
			c=c/2;
			l++;
		}
		
		printf("Case #%d: %lld %d\n",n,result1,l);
		n++;
	}
	return 0;
}