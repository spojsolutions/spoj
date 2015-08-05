#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		LL n , k;
		scanf("%lld%lld",&n,&k);
		int count = 0;
		if(k==1){
			printf("%lld\n",n);
			continue;
		}
		while(n){
			if(n%k > 0)
				count+= n%k;
			n/=k;
		}
		printf("%d\n",count);
	}
	return 0;
}