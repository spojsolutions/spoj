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
long long b[400000000];
int MOD(int base, unsigned int ex, unsigned int mod)
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
	scanf("%d",&t);
	while(t--)
	{
		int a,d,r,n,mod;
		scanf("%d%d%d",&a,&d,&r);
		scanf("%d%d",&n,&mod);
		long long first,second,ex=(n-1)/2,ex2=ex+1,gp_mod=0,temp,temp1,result;
		for(int i=0;i<ex2;i++)
			b[i]=0;
		first = ((a % mod) * MOD(r,ex,mod))%mod;
		//temp = (r-1) % mod;
		/*if(temp==0)
		{
			if(n&1)
			{
				result = (a%mod + ((d%mod) * (ex2 % mod))%mod - d%mod )%mod;
				printf("%lld\n",result);
				continue;
			}
			else
			{
				result = (a%mod + ((d%mod) * (ex2 % mod))%mod)%mod;
				printf("%lld\n",result);
				continue;
			}
		}*/
		//temp1 = MOD(r,ex2,mod);
		/*if(temp1==0)
		{
			for(int i=0;i<ex2;i++)
				temp1+=MOD(r,i,mod);
		}*/
		//cout<<MOD(r,ex2,mod)<<endl;
			for(int i=ex2-1;i>=0;i--)
				gp_mod+=MOD(r,i,mod);
		//gp_mod=(temp1/temp) % mod;
		second = ((d % mod)*(gp_mod % mod))% mod;
		if(n&1)
			printf("%lld\n",(first + second - d%mod)%mod);
		else
			printf("%lld\n",(first + second)%mod);
	}
	return 0;
}