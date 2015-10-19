/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 19 August 2015 (Wednesday) 00:53
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000007
ll dp[100009];
int last[500];
int main(){
    
    int t;
    scanf("%d ",&t);
    while(t--){
        char s[100009];
        scanf("%s", s);
        ll total = 0;
        int len = strlen(s);
        memset(dp , 0 , sizeof dp);
        memset(last , 0 , sizeof last);
        dp[0] = 1;
        for(int i = 1 ; i<= len ; i++){
            dp[i] = (dp[i-1] * 2)%mod;
            if(last[s[i-1]]!=0 ) 
                dp[i] = (dp[i] - dp[last[s[i-1]] - 1] + mod)%mod;
            last[s[i-1]] = i;
        }
        cout<<dp[len]<<endl;
    }
    
    return 0;
}