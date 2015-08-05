#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long e , o;
		cin>>e>>o;
		if((e+o)%5 == 0){
			long long cnt = (e+o)/5;
			printf("%lld\n", abs(e - 2*cnt));
		}
		else printf("-1\n");
	}
	return 0;
}