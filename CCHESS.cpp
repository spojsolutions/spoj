#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
LL dist[100][100];
map<int , pair<int , int > > mp;
map<pair<int , int > , int > m;
void fill_distance(int v){
	int path[8][2];
	int x = mp[v].first , y = mp[v].second;
	path[0][0] = x+2 , path[0][1] = y+1;
	path[1][0] = x+2 , path[1][1] = y-1;
	path[2][0] = x-2 , path[2][1] = y+1;
	path[3][0] = x-2 , path[3][1] = y-1;
	path[4][0] = x+1 , path[4][1] = y+2;
	path[5][0] = x+1 , path[5][1] = y-2;
	path[6][0] = x-1 , path[6][1] = y+2;
	path[7][0] = x-1 , path[7][1] = y-2;

	for(int i = 0 ; i < 8 ; i ++)
	{
		if(path[i][0] >= 0 && path[i][0] < 8 && path[i][1] >= 0 && path[i][1] < 8){
			dist[v][m[MP(path[i][0] , path[i][1])]] = x*path[i][0] + y*path[i][1];
		}
	}
}
void pre(){
	int k = 0;
	for(int i = 0 ; i < 64 ; i++)
		for(int j = 0 ; j < 64 ; j++){
			dist[i][j] = INT_MAX;
			dist[j][j] = 0;
		}
	for(int i = 0 ; i<64 ; i++){
		fill_distance( i);
	}
	for(int k = 0 ; k < 64 ; k++)
		for(int i = 0 ; i < 64 ; i++)
			for(int j = 0 ; j < 64 ; j++)
					dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
}
int main()
{
	int k = 0;
	for(int i = 0 ; i < 8 ; i++)
		for(int j = 0 ; j < 8 ; j++){
			mp[k] = MP(i , j);
			m[MP(i , j)] = k;
			k++;
		}
	pre();
	int x, y , u ,v;
	while(scanf("%d%d%d%d",&x , &y , &u ,&v)!=EOF){
		int source = m[MP(x,y)], dest = m[MP(u,v)];
		dist[source][dest] == INT_MAX ? printf("-1\n") : printf("%lld\n",dist[source][dest]) ;
	}
	return 0;
}