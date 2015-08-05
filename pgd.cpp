#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
int bfs(vector<int> v[],int a,int b,int n,int l)
{
	queue<pair<long long,int> > q;
	bool check[n+9];
	memset(check,false,sizeof(check));
	q.push(MP(0,a));
	while(!q.empty())
	{
		int i;
		long long wt;
		wt = q.front().first;
		i = q.front().second;
		if(check[i] == 0)
		{
			for(int k = 0;k<v[i].size();k++)
			{
				q.push(MP(wt+l,v[i][k]));
				if(v[i][k] == b)
					return wt+l;
			}
		}
		check[i] = 1;
		q.pop();
	}
	return -1;
}
int main()
{
	int n,m,q,l;
	int a,b;
	scanf("%d%d%d%d",&n,&m,&q,&l);
	vector<int> v[n+9];
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	long long sd = l;
	while(q--)
	{
		scanf("%d%d",&a,&b);
		long long chf = bfs(v,a,b,n,l);
		if(chf == -1)
			printf("not possible\n");
		else
			printf("%lld\n",chf);
	}
	return 0;
}