#include <bits/stdc++.h>
using namespace std;
#define LL long long 
#define MP make_pair
#define PB push_back
LL tree[50009];
LL read(int pos)
{
	LL res = 0;
	while(pos)
	{
		res += tree[pos];
		pos -= (pos & -pos);
	}
	return res;
}
void update(int pos,int val , int MAX)
{
	while(pos <= MAX)
	{
		tree[pos] += val;
		pos += (pos & -pos);
	}
}
bool compare(const pair<int,int> &a , const pair<int,int> &b)
{
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n+9];
	vector<pair<int , int > > v;
	v.PB(MP(0,0));
	for(int i = 1; i <= n ; i++){
		scanf("%d",&arr[i]);
		v.PB(MP(arr[i],i));
	}
	sort(v.begin(),v.end() , compare);
	LL res[n+9];
	for(int i = 1; i <= n ; i++)
		update(i,1 , n+9);
	int total = 0;
	for(int i = 1; i<=n ; i++)
	{
		total += (n - i + 1)*(v[i].first - v[i-1].first - 1) + read(v[i].second);
		res[v[i].second] = total;
		cout<<v[i].first<<"  "<<v[i].second<<endl;
		update(v[i].second , -1 , n+9);
		total += (n-i) - read(v[i].second);
	}
	for(int i = 1; i<= n ;i++)
		printf("%lld\n",res[i]);
	return 0;
}