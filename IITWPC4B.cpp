#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
#define gc getchar_unlocked
inline void scanint(unsigned long &x)
{
    register unsigned long c = gc();
    x = 0;
    unsigned long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	unsigned long t;
	scanint(t);
	while(t--)
	{
		unsigned long n;
		double temp,k;
		scanint(n);
		if(n>6)
			n=n-6;
		if(n%2==0){
			temp=(n*n)/48.0;
			printf("%.0lf\n",floor(temp+0.5));
		}
		else{
			k=(n+3)*(n+3)/48.0;
			printf("%.0lf\n",floor(k+0.5));
		}
	}
	return 0;
}