#include<stdio.h>
#include<iostream>
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
long long int A[1000010];
inline void cube()
{
	long long int i,temp=0;
	for(i=1;i<=1000000;i++)
	{
		temp=(temp + i*i*i)%1000000003;
		A[i]= (A[i-1] + temp)%1000000003;
	}
}
int main()
{
	cube();
	int t,n;
	scanint(t);
	while(t--)
	{
		scanint(n);
		printf("%lld\n",A[n]);
	}
	return 0;
}