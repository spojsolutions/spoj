/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 09 August 2015 (Sunday) 03:27
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
char opposite[200];
bool valid(int x , int y , int n , int m){
    if(x >=0 && y>=0 && y< m && x<n)
        return true;
    return false;
}
int main(){
    int n , m;
    scanf("%d%d",&n , &m);
    char arr[n+9][m+9];
    for(int i = 0 ; i < n ; i++)
        scanf("%s",arr[i]);
    int count = 0 , check[n+9][m+9];
    memset(check , 0 , sizeof check);
    int prev = 0 , color=0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            queue<pii >q;
            q.push(mp(i , j));
            vector<pii > path;
            path.pb(mp(i , j));
            if(!check[i][j]){
                color = prev + 1;
                check[i][j] = color;
                while(!q.empty()){
                    pii pos = q.front();
                    q.pop();
                    int x = pos.first , y = pos.second;
                    if(arr[x][y] == 'S')
                        x++;
                    else if(arr[x][y] == 'E')
                        y++;
                    else if(arr[x][y] == 'N')
                        x--;
                    else if(arr[x][y] == 'W')
                        y--;
                    if(valid(x , y , n , m) && check[x][y] == 0){
                        path.pb(mp(x , y));
                        q.push(mp(x , y));
                        check[x][y] = color;
                    } else if(valid(x , y , n , m) && check[x][y]!=0){
                        int save = check[x][y];
                        if(check[x][y] < color){
                            for(int p = 0 ; p < path.size() ; p++)
                                check[path[p].first][path[p].second] = check[x][y];
                        }
                        color =save;
                        break;
                    }
                }
                if(color>prev)
                    prev++;
            }
        }
    }
    cout<<prev<<endl;
    return 0;
}