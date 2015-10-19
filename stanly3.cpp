/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 26 September 2015 (Saturday) 10:49
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define MIN -1000009LL
int total_k;
int mul_val;
class data{
public:
	int size ;
	int actual;
	int val[309];
	data(){
		fill(val , val+300 , MIN);
		size = 0;
	}
	data(int a){actual = a;}
	void merge(data a){
		val[0] = max(actual , a.val[0] + actual);
		for(int i = 0 ; i<= min(a.size , total_k) ; i++){
			val[i+1] = max(val[i+1] , max(actual*mul_val + a.val[i] , actual + a.val[i+1]));
		}
		size = max(a.size+1 , size);
	}
};
data dfs(data hold[] , vector<int> graph[] , int node , int cost[]){
	if(graph[node].size() == 0){
		hold[node].size = 1;
		hold[node].actual = cost[node];
		hold[node].val[0] = cost[node];
		hold[node].val[1] = cost[node]*mul_val;
		return hold[node];
	}
	hold[node].actual = cost[node];
	hold[node].val[0] = cost[node];
	hold[node].val[1] = cost[node]*mul_val;
	for(int i = 0 ; i < graph[node].size() ; i++){
		hold[node].merge(dfs(hold , graph , graph[node][i] , cost));
	}
	return hold[node];
}
data *hold;
int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n , m , k;
		cin>>n>>m>>k;
		total_k = k;
		mul_val = m;
		int cost[n+9];
		for(int i = 0; i < n ; i++){
			cin>>cost[i];
		}
		vector<int> graph[n+9];
		for(int i = 0 ; i < n-1 ; i++){
			int a , b;
			cin>>a>>b;
			graph[a].pb(b);
		}
		int root;
		bool check[n+9];
		memset(check , 0 , sizeof check);
		for(int i = 0 ; i< n ; i++){
			for(int j = 0 ; j < graph[i].size() ; j++)
				check[graph[i][j]] = 1;
		}
		for(int i = 0 ; i < n ; i++){
			if(!check[i]){
				root = i;
				break;
			}
		}
		int ans = INT_MIN;
		hold = new data[n+9];
		dfs(hold , graph , root , cost);
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j <=total_k ; j++)
				ans = max(ans , hold[i].val[j]);
		}
		delete [] hold;
		cout<<ans<<endl;
	}
	return 0;
}