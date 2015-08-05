#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#define vii vector<int>
#define pb push_back
using namespace std;
vector<vii > D;
vector<vii > old_D;
vector<vii > graph;
vii intersection(vii a , vii b){
	vii temp;
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	set_intersection(a.begin() , a.end() , b.begin() , b.end() , back_inserter(temp));
	return temp;	
}
vii vec_union(vii a , vii b){
	vii temp;
	set_union(a.begin() , a.end() , b.begin() , b.end() , back_inserter(temp));
	return temp;
}

int main(){
	cout<<"Enter nodes and edge count\n";
	int n , e;
	cin>>n>>e;
	graph.resize(1000);
	D.resize(1000);
	old_D.resize(1000);
	for(int i = 0 ; i < e ; i++){
		int p , q;
		cin>>p>>q;
		graph[q].pb(p);
	}
	
	cout<<"Enter intial node\n";
	int initial;
	cin>>initial;
	D[initial].pb(initial);
	for(int i = 1 ; i <= n ;i++)
		if(i != initial)
			for(int j = 1 ; j<= n ; j++)
				D[i].pb(j);
	bool change = true;
	while(change){
		change = false;
		old_D = D;
		for(int i = 1 ; i<= n ; i++){
			if(i!= initial){
				vii temp;
				vii node;
				node.pb(i);
				for(int j = 0 ; j< graph[i].size() ; j++){
					if(j==0){
						temp = D[graph[i][j]];
						continue;
					}
					temp = intersection(temp , D[graph[i][j]]);
				}
				temp = vec_union(temp ,node );
				D[i] = temp;
			}
		}
		if(D != old_D)
			change = true;
	}
	for(int i = 1 ; i<= n ; i++)
	{	cout<<i<<" -> ";
		for(int j = 0 ; j < D[i].size() ; j++)
			cout<<D[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
