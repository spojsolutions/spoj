#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long 
struct node{
	int index , dist;
	node(int x , int y){index = x , dist = y;}
};
ll dist = 0;
bool visited[40009];
vector<node> v[40009];
ll dfs(int node){
	visited[node] = true;
	int l1 = 0 , l2 = 0 , dia = 0;
	for(int i = 0 ; i < v[node].size() ; i++){
		if(!visited[v[node][i].index]){
			int dia_sub_tree = dfs(v[node][i].index) + v[node][i].dist;
			if(dia_sub_tree > l1){
				l2 = l1 ;
				l1 = dia_sub_tree;
			}
			else if(dia_sub_tree > l2){
				l2 = dia_sub_tree;
			}
		}
	}

	if(dist < (l1 + l2))
		dist = l1 + l2;
	return l1 ;
}
int main(){
	int n , m , p , q , d , root = -1;
	char dir;
	scanf("%d%d", &n , &m);
	for(int i = 0 ;i < m ;  i++){
		scanf("%d %d %d %c" , &p , &q , &d , &dir);
		if(root < 0 )
			root = p;
		v[p].push_back(node(q , d));
		v[q].push_back(node(p , d));
	}
	dfs(root);
	printf("%lld\n" , dist);
	return 0;
}