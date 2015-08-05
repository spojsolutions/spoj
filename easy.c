#include<stdio.h>
#include<math.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		float A,B,C;
		scanf("%f%f%f",&A,&B,&C);
		float T,X,cs,si;
		X=C/A;
		for(i=0;i<=10000;i++)
		{
			cs=cosf(X);
		    si=sinf(X);
			T=((B*(cs-si))-C)/(A+(B*cs));
			X=T;
		}
		printf("%.6f\n",T);
	}
	return 0;
}