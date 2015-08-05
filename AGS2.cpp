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
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<int, pair<int, int> > p;
    p = extendedEuclid(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}
 
int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
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
		if(r==1)
		{
			if(!(n&1))
				printf("%lld\n",(a%mod + (d%mod)*((ex + 1) % mod))%mod);
			else
				printf("%lld\n",(a%mod + (d%mod)*(ex % mod))%mod);
			continue;
		}
		first = ((a%mod)*MOD(r,ex,mod))%mod ;
		int ex2 = ex+1;
		int find = MOD(r,ex2,mod);
		if(!find)
		{
			temp1 = mod -1;
		}
		else
			temp1= (find - 1%mod) % mod;
		temp = modInverse(r-1,mod)%mod;
		gp_mod = (temp1 * temp) % mod;
		second = ((d % mod)*(gp_mod % mod))% mod;
		if(n&1)
			printf("%lld\n",(first + second - d%mod)%mod);
		else
			printf("%lld\n",(first + second)%mod);
	}
	return 0;
}