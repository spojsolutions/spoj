/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 18 October 2015 (Sunday) 22:05
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[50009];
        ll m;
        scanf("%lld %s" , &m ,s);
        int n = strlen(s);
        vector<ll> position;
        position.pb(0);
        for(int i = 0 ; i < n ; i++)
            if(s[i] == 49)
                position.pb(i+1);
        ll median = m/2 + 1;
        ll left = 0 , right = 0;
        for(int i = 0 ; i < median ; i++)
            left += position[i];
        for(int i = median + 1 ; i<=m ; i++)
            right += position[i];
        ll ans = right - left + (2*median - m - 1)*position[median];
        int var_median = median;
        for(int i = m+1 , j = 1 ; i < position.size() ;j++, i++){
            left -= position[j];
            left += position[var_median];
            var_median++;
            right -= position[var_median];
            right += position[i];
            ll temp = right - left + (2*median - m - 1)*position[var_median];
            ans = min(ans , temp);
        }
        ans -= (m*m + 2*median*(median - 1) - 2*m*median + m)/2;
        printf("%lld\n", ans);
    }
    return 0;
}