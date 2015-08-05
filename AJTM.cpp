#include <bits/stdc++.h>
using namespace std;
int check[100009];
int carray[100009];
int main()
{
	int n , I;
	cin>>n>>I;
	vector<int> v[n+9];
	for(int i = 0 ; i < I ; i++)
	{
		int a , b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int count = 1;
	for(int i = 0 ; i < n ; i++)
	{
		if(check[i]==0){
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int x = q.front();
				for(int j = 0 ; j < v[x].size() ; j++)
					if(check[v[x][j]]==0)
				   		q.push(v[x][j]);
				check[x] = count;
				q.pop();
			}
			count++;
		}
	}
	for(int i = 0 ; i < n; i++)
		if(check[i]!=0)
			carray[check[i]]++;
	long long temp = n;
	long long total = (temp*(temp-1))/2;
	long long res = 0;
	for(int i = 1 ; i<=count ; i++)
		res += ((long long)(carray[i]*(carray[i] - 1))/2);
	cout<<total - res<<endl;
	return 0;
}