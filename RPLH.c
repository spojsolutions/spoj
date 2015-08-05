#include<stdio.h>
#include<math.h>
#define g 9.806
int main()
{
	int t,n=1;
	scanf("%d",&t);
	while(n<=t)
	{
		double D,A,R,velocity;
		scanf("%lf%lf",&D,&velocity);
		R=(D*g)/(velocity*velocity);
		if(R>1||R<0)
			printf("Scenario #%d: -1\n",n);
		else
		{
		A=(asin(R)/2)*(180/(2*acos(0.0)));
		printf("Scenario #%d: %.2lf\n",n,A);
		}
		n++;
	}
	return 0;
}