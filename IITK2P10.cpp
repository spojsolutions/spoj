#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
LL pow_mod(LL a , LL b , LL mod){
	LL res = 1 , p = a;
	while(b){
		if(b&1)
			res = (res * p)%mod;
		p = (p*p)%mod;
		b>>=1;
	} 
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		LL k , n;
		cin>>k>>n;
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		if(n==2)
		{
			printf("%lld\n",k);
			continue;
		}
		LL temp = pow_mod(2 , n-3, MOD-1);
		LL res = pow_mod(k , temp , MOD);
		cout<<res<<endl;
	}
	return 0;
}