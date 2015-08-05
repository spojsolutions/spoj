#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,x;
		scanf("%d %d %d",&n,&m,&x);
		long long arr[n],cum[m];
		memset(cum,0,sizeof(cum));
		for (int i=0; i<n; i++)
		{
			scanf("%lld",&arr[i]);
			arr[i]%=m;
			cum[arr[i]]++;
		}
		for (int i=1; i<m; i++)
			cum[i]+=cum[i-1];
		sort(arr,arr+n);
		long long ans=0;
		for (int i=m-1; i>x; i--)
		{
			int up_bound=m+x-i,low_bound=m-i;
			ans+=(cum[up_bound]-cum[low_bound-1])*(cum[i]-cum[i-1]);
		}
		for (int i=x; i>0; i--)
		{
			int up_bound=m-i,low_bound=x-i;
			ans+=(cum[m-1]-cum[up_bound-1])*(cum[i]-cum[i-1]);
			ans+=(cum[low_bound])*(cum[i]-cum[i-1]);
		}
		ans+=(cum[x])*cum[0];
		printf("%lld\n",ans);
	}
	return 0;
}//9939040626