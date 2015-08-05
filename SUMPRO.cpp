#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long res = 0;
		int flag = 0;
		int val = sqrt(n);
		if(val * val == n)
			flag = 1;
		for(int i = 1 ; i*i < n ; i++){
			if(n%i == 0){
				long long temp = n/i;
				res = (res + (2*i*temp) ) %MOD;
			}
		}
		if(flag)
			res = (res + n)%MOD;
		long long rem = (long long)((n-1)*n)/2;
		rem = rem - (long long)((val+2)*(val+1))/2;
		printf("%lld\n", (res + (rem<0 ? 0 : rem))%MOD);
	}
	return 0;
}