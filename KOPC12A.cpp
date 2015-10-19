/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 12 August 2015 (Wednesday) 01:47
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
ll check(vector<int> &v ,vector<int> &c, int h){
    ll sum = 0;
    for(int i = 0 ; i < v.size() ; i++){
        ll diff = abs(v[i] - h);
        sum += diff*c[i];
    }
    return sum;
}
ll b_search(vector<int> &v , vector<int>&c){
    ll low = 0 , mid , high = INT_MAX;
    ll p , n , m , ans = LLONG_MAX;
    while(low<high){
        mid = (low+high)>>1;
        mid > 0 ? p = check(v , c , mid-1): INT_MAX;
        m = check(v , c , mid);
        n = check(v , c , mid+1);
        //cout<<p<<" "<<m<<" "<<n<<endl;
        if(ans == m)
            break;
        ans = min(ans , m);
        if(p <= m)
            high = mid;
        else if(n <= m)
            low = mid+1;
    }
    return ans;
}
int main(){
    
    int t;
    scanf("%d" , &t);
    while(t--){
        int n , temp;
        scanf("%d",&n);
        vector<int> v(n) , c(n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&temp);
            v[i] = temp;
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&temp);
            c[i] = temp;
        }
        printf("%lld\n", b_search(v , c));
    }
    
    return 0;
}