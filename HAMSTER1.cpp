#include <stdio.h>
#include <cmath>
#define PI 3.14159265
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		float v,k1,k2;
		float angle;
		scanf("%f%f%f",&v,&k1,&k2);
		if(k1==0)
			angle=PI/2.0;
		else if(k2==0)
			angle=PI/4.0;
		else{
			angle=atan(-4.0*k1/k2)/2;
			if(angle<0)
				angle+=PI/2;}
		printf("%.3f %.3f\n",angle,(v*v/10.0)*(k1*sin(2.0*angle)+k2*sin(angle)*sin(angle)/2));
	}
	return 0;
}