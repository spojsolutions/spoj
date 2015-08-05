#include<stdio.h>
#include<stdlib.h>
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,i;
		long long a,sum=0;
		scanint(n);
		for(i=0;i<n;i++){
			scanint(a);
			sum=(sum+a)%n;}
		if(sum%n==0)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}