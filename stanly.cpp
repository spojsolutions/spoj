/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 25 September 2015 (Friday) 20:06
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int p[500000];
int weight[500000];
map<pair<int , int > ,int> mp;
int find(int n){
    if(p[n] == n)
        return n;
    return p[n] = find(p[n]);
}
void unio(int a , int b){
    int par_a = find(a);
    int par_b = find(b);
    if(par_b == par_a)
    	return ;
    p[par_a] = par_b;
    int save = weight[par_b];
    weight[par_b] += weight[par_a];
    auto it = mp.find(make_pair(weight[par_a] , par_a));
    if(it!=mp.end())
        mp.erase(it);
    it = mp.find(make_pair(save , par_b));
    if(it!=mp.end())
        mp.erase(it);
    mp[make_pair(weight[par_b] , par_b)] = 1;
    weight[par_a] = 0;
}
int main(){
    int n , q;
    cin>>n>>q;
    for(int i = 1 ; i <= n ; i++){
        p[i] = i;
        cin>>weight[i];
        mp[make_pair(weight[i] , i)];
    }
    for(int j = 0 ; j <q ; j++){
        int a , b;
        cin>>a>>b;
        unio(a , b);
        cout<<mp.begin()->first.first<<endl;
    }
    return 0;
}