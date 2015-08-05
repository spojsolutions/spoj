#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fact(int n){
	ll ans = 1;
	for(int i = 1 ; i <= n ; i++)
		ans *= i;
	return ans;
}
int main(){
	int n;
	int t;
	cin>>t;
	while(t){
		cin>>n;
		ll factorial = fact(n);
		int ans = 0;
		for(ll i = 1 ; i<= factorial/2 ; i++){

			ll sum = 0;
			ll count = i;
			ll flag = 0;
			while(true){
				sum += count;
				if(sum == factorial){
					flag = count ;
					break;
				}
				if(sum > factorial){
					flag = 0;
					break;
				}
				count++;
			}
			if(flag && count - i + 1 >= 2){
				ans++;
				cout<<i<<" " <<count<<endl;
			}
		}
		cout<<"ANS :-  "<<ans<<endl;
	}
	return 0;
}