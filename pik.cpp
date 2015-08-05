#include <bits/stdc++.h>
using namespace std;
bool check[100009];
vector<int> v[100009];
void dfs( int i){
    cout<<i<<endl;
    if(!check[i]){
        check[i] = 1;
        for(int j = 0 ; j < v[i].size() ; j++)
            if(!check[v[i][j]])
                dfs(v[i][j]);
    }
}
int main() {
    int t;
   
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        for(int i = 0 ; i <= n ; i++)
            v[i].clear();
        for(int i = 0 ; i < m ; i++){
            int a , b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(check , 0 , sizeof check);
        queue<int> q;
        int count = 0;
        for(int i = 1 ; i<= n ; i++){
            if(!check[i]){
                dfs(i);
                count++;
            }   
        }
        cout<<count-1<<endl;
    }
    return 0;
}