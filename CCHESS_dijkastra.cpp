#include <bits/stdc++.h>
using namespace std;
struct cmp
{
	bool compare()(const pair<int , pair<int ,int > > &a , const pair<int , pair<int ,int > >&b ){
		return a.first < b.first;
	}
};
int main(){
	int x,y,u,v;
	while(scanf("%d%d%d%d",&x,&y,&u,&v)!=EOF){
		int dist[70];
		for(int i = 0 ; i <= 70 ; i++)
			dist[i] = 9999999;
		priority_queue<pair<int , pair<int , int > > , vector<pair<int , pair<int , int> > > , compare > pq;
		
	}
}