#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
LL pow_mod(LL a , LL b){
	LL res = 1 , p = a;
	while(b){
		if(b&1)
			res = (res * p)%MOD;
		p = (p*p)%MOD;
		b>>=1;
	} 
	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		LL n , m;
		cin>>n>>m;
		if(n ==1){
			cout<<m<<endl;
			continue;
		}
		if(n==2){
			cout<<m*(m-1)<<endl;
			continue;
		}
		if(m<=2){
			cout<<0<<endl;
			continue;
		}
		LL res = pow_mod(m-2 , n-2);
		res = (res * m)%MOD;
		res = (res * (m-1))%MOD;
		cout<<res<<endl;
	}
	return 0;
}