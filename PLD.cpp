/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 15 September 2015 (Tuesday) 00:19
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define base 1223
ll prime[30009] , fh[30009] , bh[30009];
void prime_power(int n){
    prime[0] = 1;
    for(int i = 1 ; i <= n + 5 ; i++)
        prime[i] = (prime[i-1]*base)%mod;
}
void Hash(string &s , int n){
    for(int i = 1, j = n ; i<= n ;j--, i++){
        fh[i] = (fh[i-1] + s[i-1]*prime[i])%mod;
        bh[j] = (bh[j+1] + s[j-1]*prime[i])%mod;
    }
}
int count_palindromic_substring(string &s , int k){
    int n = s.size();
    int count = 0;
    int flag = 1;
    for(int i = k , j = 0 ,p_pow = n-k ; i<= n ;p_pow-=2 , j++,i++){
        ll hs1 , hs2;
        if(p_pow>=0){
            hs1 = (fh[i] - fh[j] + mod)%mod;
            hs1 = (hs1*prime[p_pow])%mod;
            hs2 = (bh[j+1] - bh[i+1] + mod)%mod;
        } else{
            hs2 = (bh[j+1] - bh[i+1] + mod)%mod;
            hs2 = (hs2*prime[abs(p_pow)])%mod;
            hs1 = (fh[i] - fh[j] + mod)%mod;
        }
        if(hs1 == hs2)
            count++;
    }
    return count;
}
int main(){
    
    string s ;
    int k;
    cin>>k>>s;
    prime_power(s.size());
    Hash(s , s.size());
    cout<<count_palindromic_substring(s , k)<<endl;
    return 0;
}