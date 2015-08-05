#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
LL pow_mod(int a)
{
	LL res = 1,p = 2;
	while(a)
	{
		if(a&1)
			res = (res*p)%MOD;
		p = (p*p)%MOD;
		a>>=1;
	}
	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		LL res;
		int a = (n-1)&1 ? -1 : 1;
		res = (MOD + (3*(pow_mod(n-1)))%MOD - a)%MOD;
		cout<<res<<endl;
	}
	return 0;
}