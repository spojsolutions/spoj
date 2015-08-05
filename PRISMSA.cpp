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
		int v;
		scanf("%d",&v);
		double p;
		p=0.6666666666666666;
		printf("%.10lf\n",(sqrt(27)/2)*(pow((4*v),p)));
	}
	return 0;
}