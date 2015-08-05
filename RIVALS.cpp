#include <bits/stdc++.h>
using namespace std ;
#define LL long long
#define MOD 1000000007
LL arr[2000009];
void pre()
{
    arr[0] = 1;
    arr[1] = 1;
    for(LL i = 2 ; i<=2000000 ; i++)
        arr[i] = (arr[i-1] * i)%MOD;
}
LL inv_mod(LL x)
{
    LL a = 1 , p = x , n = 1000000005;
    while(n) 
    {
        if(n&1)
            a = (a*p)%MOD;
        p = (p * p )%MOD;
        n>>=1;
    }
    return a;
}
int main()
{
    int t;
    pre() ;
    scanf("%d",&t);
    while(t--)
    {
        int x , y;
        scanf("%d%d",&x , &y);
        LL temp = (inv_mod(arr[x]) * inv_mod(arr[y]))%MOD;
        LL res = (arr[x+y] * temp)%MOD;
        printf("%lld\n",res);
    }
    return 0;
}