#include <bits/stdc++.h>
using namespace std;
int tree[1009];
int n,m,k;
struct compare
{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b)
	{
		return a.first!=b.first ? a.first<b.first : a.second<b.second;
	}
};
void update(int idx)
{
	while (idx<=m)
	{
		tree[idx]+=1;
		idx += idx & -idx;
	}
}
int query(int idx)
{
	int sum=0;
	while(idx)
	{
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main()
{
	int t,j=0;
	scanf("%d",&t);
	while (t--)
	{		
		scanf("%d %d %d",&n,&m,&k);
		vector<pair<int,int> > v;
		for (int i=0; i<k; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			v.push_back(make_pair(a,b));
		}
		sort(v.begin(),v.end(),compare());
		long long int count=0;
		memset(tree,0,sizeof(tree));
		for (int i=0; i<k; i++)
		{
			count+=query(m)-query(v[i].second);
			update(v[i].second);
		}
		printf("Test case %d: %lld\n",++j,count);
	}
	return 0;
}
