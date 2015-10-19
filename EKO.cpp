/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 12 August 2015 (Wednesday) 02:14
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
ll woodCut(vector<ll> &v , ll h){
    ll sum = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] > h)
            sum += v[i]-h;
    }
    return sum;
}
ll b_search(vector<ll> &v , ll required){
    ll low = 0 , mid , high = LLONG_MAX/10;
    ll ans = LLONG_MIN;
    while(low < high){
        mid = (low + high)>>1;
        ll wood = woodCut(v , mid);
        if(wood >= required){
            low = mid+1;
            ans = max(ans , mid);
        }
        else
            high = mid;
    }
    return ans;
}
int main(){
    
    ll n , m;
    scanf("%lld%lld" , &n , &m);
    vector<ll> v(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&v[i]);
    }
    printf("%lld\n",b_search(v , m));
    return 0;
}