#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MAX 30000
int tree[30009];
void update(int pos,int val)
{
	while(pos <= MAX)
	{
		tree[pos] += val;
		pos += (pos & -pos);
	}
}
int read(int pos)
{
	int res = 0;
	while(pos)
	{
		res += tree[pos];
		pos -= (pos & -pos);
	}
	return res;
}
struct tuple
{
	int idx , l , r , val;
	bool type;
	tuple(int a,int b,int c,int d , bool e)
	{
		idx = a;
		l = b;
		r = c;
		val = d;
		type = e;
	}
};
bool compare(const tuple &a , const tuple &b)
{
	return a.r == b.r ? a.type < b.type : a.r < b.r;
}
int ans[300009];
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n+9],temp;
	vector<tuple> v;
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",&temp);
		v.PB(tuple(i+1,0,i+1,temp,false));
	}
	int q,l,r;
	scanf("%d",&q);
	for(int i = 0 ; i < q;i ++)
	{
		scanf("%d%d",&l,&r);
		v.PB(tuple(i + 1 , l , r, 0 , true));
	}
	for(int i = 1 ; i <= n; i++)
		update(i , 1);
	int visit_pos[1000009];
	memset(visit_pos , 0 ,sizeof visit_pos);
	sort(v.begin(),v.end() , compare);
	for(int i = 0 ; i < n + q ; i++)
	{
		if(v[i].type){
			ans[v[i].idx] = read(v[i].r) - read(v[i].l - 1);
		}
		else
		{
			if(visit_pos[v[i].val]!=0){
				update(visit_pos[v[i].val] , -1);
			}
			visit_pos[v[i].val] = v[i].idx;
		}
	}
	for(int i = 1 ; i <= q; i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}