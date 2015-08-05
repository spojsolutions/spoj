#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		float s;
		double p;
		scanf("%f",&s);
		s=s/2;
		p=(1 - 1/(3*sqrt(s)));
		printf("%0.6lf\n",p);
	}
	return 0;
}