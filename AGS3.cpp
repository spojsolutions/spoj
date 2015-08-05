#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
#include <fstream>
#include <sstream>
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
long long MOD(int base, unsigned int ex, unsigned int mod)
{
    long long x = base % mod;
    long long p =1;
   while(ex >0)
   {
   		if(ex  & 1)
   		{
   			p*=x;
   			p=p%mod;
   		}
   		ex/=2;
   		x=(x*x)%mod;
   }

    return p;
}
long long geo_sum(int r,int n,int m)
{
	if(n==0)
		return 1%m;
	if(n==1)
		return (1+r)%m;
	if(n&1)
		return (( 1 + MOD(r,(n+1)>>1,m)) * (geo_sum(r,(n-1)>>1,m)%m))%m;
	else
		return ( (1 + MOD(r,(n)>>1,m)) * (geo_sum(r,(n-1)>>1,m)%m) + MOD(r,n,m))%m;
}
int main()
{
	int t;
	scanint(t);
	while(t--)
	{
		int a,d,r,n,mod,b[1000000];
		scanint(a);
		scanint(d);
		scanint(r);
		scanint(n);
		scanint(mod);
		long long first,second,ex=(n-1)>>1,gp_mod=0,temp,temp1,result;
		if(n==1)
		{
			printf("%d\n",a%mod);
			continue;
		}
		if(n==2)
		{
			printf("%d\n",(a%mod + d%mod)%mod);
			continue;
		}
		if(!(n&1))
			printf("%lld\n",(((a%mod)*(MOD(r,ex,mod)))%mod + ((d%mod)*(geo_sum(r,ex,mod)))%mod)%mod);
		else
			printf("%lld\n",(((a%mod)*(MOD(r,ex,mod)))%mod + ((d%mod)*(geo_sum(r,ex,mod)))%mod - d%mod)%mod);
	}
	return 0;
}