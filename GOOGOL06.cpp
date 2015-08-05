#include <bits/stdc++.h>
using namespace std;
#define MOD 215372682525
#define ll long long
int main(){
	int t;
	cin>>t;
	while(t--){
		int a , d , n , x;
		cin>>a>>d>>n>>x;
		ll pre_com[n+9];
		pre_com[0] = 1;
		ll sum_x = 1;
		for(int i = 1 ; i <= n ; i++){
			pre_com[i] = (pre_com[i-1]*x)%MOD;
			sum_x = (sum_x + pre_com[i])%MOD;
		}
		sum_x  = (sum_x*a) %MOD;
		ll sum_d = 0;
		for(int i = 0 ; i <=n ; i++){
			sum_d = (sum_d + (i*(pre_com[n - i]))%MOD)%MOD;
		}
		sum_d = (sum_d*d)%MOD;
		cout<<(sum_d + sum_x)%MOD<<endl;
	}
	return 0;
}