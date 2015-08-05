#include <bits/stdc++.h>
using namespace std;
bool primes[10000009];
int cum[10000009];
void pre(){
    for(int i = 3 ; i<= 3163 ; i+=2){
        if(!primes[i]){
            for(int j = i*i ; j<= 10000000 ; j+=2*i)
                primes[j] = 1;
        }
    }
    cum[2] = 1;
    for(int i = 3 ; i<=10000000 ; i++){
        if(primes[i] == 0 && i%2 != 0)
            cum[i] += cum[i-1] + 1;
        else
            cum[i] = cum[i-1];
    }
}
int main(){
    int t;
    pre();
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n" , cum[n] - cum[(n>>1)]);
    }
    return 0;
}