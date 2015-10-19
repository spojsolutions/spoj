/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 11 September 2015 (Friday) 21:19
===================================================*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define pii pair < int , int >
// #define pb push_back
// #define mp make_pair
// #define mod 1000000009
// int fn(int x , int y){
// 	cout<<x<<" "<<y<<endl;
// 	if(x == 0)
// 		return y+1;
// 	if(x > 0 && y == 0)
// 		return fn(x-1 , 1);
// 	if(x > 0 && y > 0)
// 		return fn(x-1 , fn(x , y-1));
// }
// int main(){
	
// 	int n , m;
// 	cin>>n>>m;
// 	cout<<fn(n , m)<<endl;
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 555555;
vector<int> g[N];
ll wt[N];
bool vis[N];
ll dfs(int root){
	if (vis[root]) return 0;
	vis[root] = true;
	vector<ll> child;
	for(int i = 0; i<g[root].size(); i++){
		child.push_back(dfs(g[root][i]));
	}
	int mx = 0;
	ll sum = 0;
	for (int i = 0; i<child.size(); i++){
		if (child[mx] < child[i])
			mx = i;
		sum += child[i];
	}
	return 
}
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	scanf("%d", &n);
	for (int i = 1; i<=n; i++)
		scanf("%lld", &wt[i]);
	
	vector<pair<int, int> >edges;
	for (int i = 0; i<n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll res = 0;
	
	printf("%lld\n", res);
	return 0;
}
