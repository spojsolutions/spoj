#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		long long  p;
		cin>>a>>b>>p;
		long long  arr[p+9],cum[p+9];
		memset(arr,0,sizeof(arr));
		memset(cum,0,sizeof(cum));
		for(long long  i=1;i<p;i++){
			long long mod =(i*i*i)%p;
			if(mod == 1)
				arr[i] = 1;
			cum[i] = arr[i] + cum[i-1];
		}
		long long  last = b / p;
		long long res =(long long ) last * cum[p-1];
		res += cum[b%p];
		last = a/p;
		res -= (long long ) last * cum[p-1];
		res -= cum[max(a%p -1 , 0LL)];
		cout<<res<<endl;
	}
	return 0;
}