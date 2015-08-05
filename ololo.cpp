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
	int n,i,temp,sum;
	scanint(n);
	sum=0;
	for(i=0;i<n;i++)
	{
		scanint(temp);
		sum=sum^temp;
	}
	printf("%d\n",sum);
	return 0;
}