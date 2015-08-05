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
		string s[n+9],temp;
		for(int i = 0;i < n;i++)
			cin>>s[i];
		int count = 1;
		map<string,int> mp;
		while(count<=n){
			cin>>temp;
			mp[temp] = count;
			count++;
		}
		int arr[n+9];
		count = 0;
		for(int i = 0;i<n;i++)
			arr[i] = mp[s[i]];
		LL tree[n+9];
		memset(tree,0,sizeof tree);
		LL total = 0;
		for(int i = n - 1 ; i >= 0 ; i--)
		{
			total += read(tree,arr[i]);
			update(tree,arr[i],1,n+9);
		}
		printf("%lld\n", total);
	}
	return 0;
}