/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 17 August 2015 (Monday) 04:58
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define mod 1000000009
int x[8] = {-1,1,-2,2,-2,2,-1,1};
int y[8] = {-2,-2,-1,-1,1,1,2,2};
int n , m;
bool valid(int row , int col){
    if(row>=0 && row< n && col >=0 && col < m)
        return true;
    return false;
}
bool dfs(vector<string> path ,int row ,int col , int count, int check[][30]){
    string temp = "";
    char c = (char)(col + 65);
    temp.pb(c);
    temp.append(to_string(row+1));
    path.pb(temp);
    if(count == m*n){
        for(int i = 0 ; i < path.size() ; i++)
            cout<<path[i];
        cout<<endl;
        return true;
    }
    int p , q;
    for(int i = 0 ; i < 8 ; i++){
        p = row + x[i] , q = col + y[i];
        if(valid(p , q) && !check[p][q]){
            check[p][q] = 1;
            if(dfs( path , p , q , count+1 , check)) return true;
            check[p][q] = 0;
        }
    }
    return false;
}
bool path(){
    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < m ; j++){
            int check[30][30];
            memset(check , 0 , sizeof check);
            check[i][j] = 1;
            vector<string> path;
            if(dfs(path , i , j ,1 , check )) return true;
        }
    }
    return false;
}
int main(){ 
     
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(!path()) cout<<-1<<endl;
    }
    
    return 0;
}