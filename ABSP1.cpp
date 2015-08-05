#include <stdio.h>
#include <iostream>
using namespace std;
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanint(n);
		int a[n+9];
		for(i=0;i<n;i++)
			scanint(a[i]);
		long long sum=0;
		for(i=0;i<n/2;i++)
		{
			sum+=((n- 2*i -1)*(a[n-i-1] - a[i]));
		}
		printf("%lld\n",sum);
	}
	return 0;
}