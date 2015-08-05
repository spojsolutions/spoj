#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define LL long long
bool compare(const pair<int,int> &a,const pair<int ,int> &b)
{
	return a.first == b.first ? a.second < b.second : a.first<b.first;
}
int main()
{
	int n,k,a,b;
	cin>>n>>k;
	int arr[n+9];
	vector<pair< int ,int> > v;
	int x[k+9],y[k+9];
	for(int i =0 ;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		if(a<b)
			v.PB(MP(a,b));
		else
			v.PB(MP(b,a));
	}
	sort(v.begin(),v.end(),compare);
	LL ma=v[0].second,mi=v[0].first;
	int l =0 ;
	for(int i = 1;i<k;)
	{
		while(i<k && v[i].first <= ma)
		{
			ma = max(ma,(LL)v[i].second);
			i++;
		}
		x[l] = mi;
		y[l] = ma;
		l++;
		if(i<k){
			mi = v[i].first;
			ma = v[i].second;}
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		int pos = lower_bound(x,x+l,arr[i]) - x;
		if((pos <l && x[pos] <= arr[i] && y[pos] >= arr[i]) || ((pos>0 && pos<=l) && x[pos-1] <= arr[i] && y[pos-1] >= arr[i]) )
			count++;
	}
	cout<<count<<endl;
	return 0;
}