#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
#define LOG_MAX 16
struct node{
	int index , distance;
	node(int x , int y){ index = x , distance = y; }
};
int s_table[40009][LOG_MAX+1] , level[40009] , parent[40009] , n;
long long dist[40009];
vector<node> tree[40009];
int visited[40009];
void dfs(int node){
	visited[node] = true;
	for(int i = 0 ; i < tree[node].size() ; i++){
		if(!visited[tree[node][i].index]){
			dist[tree[node][i].index] = dist[node] + tree[node][i].distance;
			level[tree[node][i].index] = level[node] + 1;
			parent[tree[node][i].index] = node;
			dfs(tree[node][i].index);
		}
	}
}
void pre_calculate(){

	memset(s_table , -1 , sizeof s_table);
	for(int i = 1 ; i <= n ; i++)
		s_table[i][0] = parent[i];

	for(int j = 1 ; (1<<j) <= n ; j++)
		for(int i = 1 ; i <= n ; i++)
			if(s_table[i][j-1] != -1)
				s_table[i][j] = s_table[s_table[i][j-1]][j-1]; 
}
int get_lca(int p , int q){

	if(level[p] < level[q])
		swap(p , q);

	int log_p;
	for(log_p = 1 ; (1<<log_p) <= level[p] ; log_p++);
	log_p--;
	
	for(int i = log_p ; i>=0 ; i--)
		if(level[p] - (1<<i) >= level[q])
			p = s_table[p][i];

	if(p == q)
		return p;
	for(int i = log_p ; i>=0 ; i--)
		if(s_table[p][i] != -1  && s_table[p][i] != s_table[q][i])
			p = s_table[p][i] , q = s_table[q][i];
	// cout<<" p = "<<p<<" " << parent[p]<<endl;
	return parent[p];
}
int main(){
	int m;
	scanf("%d%d",&n , &m);
	int p , q , d , root = -1;
	char dir ;
	for(int i = 0 ; i < m ; i++){
		scanf("%d %d %d %c",&p , &q , &d , &dir);
		// cin>>p>>q>>d>>dir;
		if(root < 0)
			root = p;
		tree[p].push_back(node(q , d));
		tree[q].push_back(node(p , d));
	}
	dist[root] = 0;
	level[root] = 0;
	parent[root] = -1;
	dfs(root);
	pre_calculate();
	/*cout<<"root = "<<root<<endl;
	for(int i = 0 ; i <= n ; i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	for(int i = 0 ; i <= n ; i++)
		cout<<level[i]<<" ";
	cout<<endl;*/
	int k;
	cin>>k;
	while(k--){
		// cin>>p>>q;
		scanf("%d %d" , &p , &q);
		int lca = get_lca(p , q);
		// cout<<"lca = "<<lca<<endl;
		// cout<<dist[p] + dist[q] - (2*dist[lca])<<endl;
		printf("%lld\n", dist[p] + dist[q] - (2*dist[lca]));
	}
	return 0;
}