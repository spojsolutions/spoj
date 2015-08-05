#include <iostream>
#include <sstream>

using namespace std;
#include<stdio.h>>>>
#define ULL unsigned long long
#define MOD 1000000007

ULL n;
unsigned int p;

ULL pow_mod(ULL p,ULL n){
    ULL x=1;
    while(n)
    {
        if(n&1)
            x=(x*p)%MOD;

        p=(p*p)%MOD;
        n>>=1;
    }
    return x;
}
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    if(a == 0)
        return make_pair(b, make_pair(0, 1));

    pair<int, pair<int, int> > p;

    p = extendedEuclid(b % a, a);

    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}

int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

int main(){

    int t,l;
    scanf("%d",&t);

    while(t--){
    	ULL z,m;
    	scanf("%lld %d",&n,&p);
    	if(n>1 && p>1){
    		m=(pow_mod(p,n-1));
    		z=(((m*p-1)%MOD)*modInverse(p-1,MOD))%MOD;
    		printf("%lld %lld\n",z,m%MOD);
    	}
    }
    return 0;
}


