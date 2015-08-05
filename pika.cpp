#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
int check[n+9][n+9];
int main() {
    int n;
    cin>>n;
    string s[n+9];
    for(int i = 0 ; i < n ; i++)
    	cin>>s[i];
    for(int i = 0 ; i < n ; i++)
    {
    	for(int j = 0 ; j < n ; j++)
    	{
    		if(!check[i][j] && s[i][j] == 'X')
    		{
    			queue<pair<int , int> > q;
    			int min_x = 999999 , min_y = 9999999, max_x = -1 , max_y = -1 , x , y;
    			q.push(MP(i , j));
    			while(!q.empty())
    			{
    				x = q.front().first;
    				y = q.front().second;
    			}
    		}
    	}
    }
    return 0;
}