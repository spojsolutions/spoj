#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define ULL unsigned long long
int ways(int N){
    int total_ways = 0;

    if (N == 1)
        return 1;

    for (int i = 1 ; i<= N ; i++){
        if (i == 1 or i == N){
            total_ways = total_ways + ways(N - 1);
            total_ways = total_ways + 2;
        }
        else{
            total_ways = total_ways + ways(i - 1);
            total_ways = total_ways + ways(N - i);
            total_ways = total_ways + 1;
        }
    }
    return total_ways;
}
ULL pow_mod(ULL n , ULL b){
    ULL a = 1 , p = n;
    while(b){
        if(b&1)
            a = (a*p)%MOD;
        p = (p * p)%MOD;
        b>>=1;
    }
    return a;
}
int main(){
    
    int n;
    cin>>n;
    cout<<ways(n) - pow_mod(2 , n-1)<<endl;
    
    return 0;
}
