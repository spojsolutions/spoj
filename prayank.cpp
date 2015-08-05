#include <stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	long long a[n],su,an;
	for(i=0;i<n;i++)
		scanf("%llu",&a[i]);
	su=an=a[0];

	for(i=1;i<n;i++)
	{
		an=an&a[i];
		su=su|a[i];
	}
	an=~an;
	printf("%llu\n",an&su);
	return 0;
}