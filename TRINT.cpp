#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int arr[n+9];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		long long count = 0;
		for(int i=0;i<n;i++)
		{
			int j = i+1;
			int k = n-1;
			while(j<k)
			{
				if(arr[i] + arr[j] + arr[k] <= m)
				{
					for(int l = k;l>j;l--)
						cout<<i<<" "<<j<<" "<<l<<endl;
					count += k - j;
					j++;
				}
				else
					k--;
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}