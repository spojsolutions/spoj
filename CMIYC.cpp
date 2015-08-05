#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
#define LL long long
#define gc getchar_unlocked
inline void scanint(LL &x)
{
    register LL c = gc();
    x = 0;
    LL neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	LL t;
	scanint(t);
	while(t--)
	{
		LL n;
		scanint(n);
		if(n%3==0)
			printf("%lld\n",n/3);
		else
			printf("0\n");
	}
	return 0;
}