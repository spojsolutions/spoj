/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 08 September 2015 (Tuesday) 20:11
===================================================*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
struct cmp
{
	bool operator()(const pair<int , int> &a , const pair<int , int> &b){
		return a.first > b.first;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		vector<int> graph[n+9];
		vector<vector<int> > cost(n+1 , vector<int>(n+1 , 0));
		map<string, int> map_name;
		for(int i = 1 ; i <= n ; i++){
			// char temp[12];
			// scanf("%s", temp);
			// s.assign(temp);
			cin>>s;
			map_name[s] = i;
			int path , k , c;
			// scanf("%d", &path);
			cin>>path;
			for(int j = 0 ; j < path ; j++){
				// scanf("%d%d" , &k , &c);
				cin>>k>>c;
				graph[i].pb(k);
				cost[i][k] = c;
			}
		}
		int k;
		// scanf("%d" , &k);
		cin>>k;
		while(k--){
			// for(int i = 1 ; i <= n ; i++){
			// 	for(int j = 0 ; j < cost[i].size() ; j++)
			// 		cout<<cost[i][j]<<" ";
			// 	cout<<endl;
			// }
			char source_temp[12] , dest_temp[12];
			string source , dest;
			// scanf("%s%s" , source_temp , dest_temp);
			source.assign(source_temp);
			dest.assign(dest_temp);
			cin>>source>>dest;
			priority_queue<pii , vector<pii >, cmp > pq;
			ll dist[n+9];
			fill(dist , dist+n , INT_MAX-100000);
			int dist_num = map_name[dest] , source_num = map_name[source];
			dist[source_num] = 0;
			pq.push(mp(0 , source_num));
			while(!pq.empty()){
				int wt = pq.top().first;
				int node = pq.top().second;
				pq.pop();
				if(node == dist_num){
					// printf("%d\n", wt);
					cout<<wt<<endl;
					break;
				}
				//cout<<node<<" "<<wt<<endl;
				for(auto it:graph[node]){
					//cout<<node<<" "<<it<<" cost "<<cost[mp(node , it)]<<endl;
					if(dist[it] > dist[node] + cost[node][it]){
						dist[it] = dist[node] + cost[node][it];
						pq.push(mp(dist[it] , it));
					}
				}
			}
		}
	}
	
	return 0;
}