#include <bits/stdc++.h>
using namespace std;
#define LL long long
void update(LL arr[],int pos,int val,int MAX)
{
	while(pos<=MAX)
	{
		arr[pos] += val;
		pos += (pos & -pos);
	}
}
LL read(LL arr[],int pos)
{
	LL sum = 0;
	while(pos)
	{ 
		sum += arr[pos];
		pos -= (pos & -pos);
	}
	return sum;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n+9],hold[n+9];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			hold[i] = arr[i];
		}
		sort(arr,arr+n);
		for(int i = 0; i < n ; i++)
		{
			int pos = lower_bound(arr,arr+n,hold[i]) - arr;
			hold[i] = pos + 1;
		}
		LL total = 0;
		LL tree[n+9];
		memset(tree,0,sizeof(tree));
		for(int i = n - 1 ; i>=0 ; i--)
		{
			total += read(tree,hold[i]);
			update(tree,hold[i] , 1 , n+9);
		}
		printf("%lld\n",total);
	}
	return 0;
}