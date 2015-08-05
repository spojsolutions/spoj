#include<stdio.h>
#include<iostream>
using namespace std;
#define gc getchar_unlocked
inline void scanint(long long &x)
{
    register long long c = gc();
    x = 0;
    long long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	long long t,n,k,m,total;
	scanint(t);
	while(t--)
	{
		scanint(n);
		scanint(k);
		scanint(m);
		int count=0;
		if(k<=m/n)
		{
			count++;
			total=n*k;
			while(k<=m/total)
			{
				count++;
				total*=k;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}