#include <bits/stdc++.h>
using namespace std;
#define LL long long 
LL solve(LL a,LL b,LL t)
{
    LL res = (t - a) < 0 ? 0 : (t-a)/b + 1;
    return res;
}
LL calculate(LL a[] , LL b[] , LL t , int sz)
{
    int total = 0;
    for(int i = 0 ; i < sz ; i++)
        total += solve(a[i] , b[i] , t);
    return  total;
}
LL b_search(LL a[] , LL b[] , LL c[] , LL d[] , LL t ,int sa, int sc)
{
    LL low = 1 , high = t , mid , lhalf , rhalf , ma = -1;
    while(low < high)
    {
        mid = (low + high)>>1;
        lhalf = calculate(a,b,mid,sa);
        rhalf = calculate(c,d,t - mid , sc);
        if(lhalf <= rhalf){
            low = mid + 1;
            ma = max(mid,ma);
        }
        else if(lhalf > rhalf)
            high = mid;
    }
    return ma;
}
int main()
{
    LL t;
    scanf("%lld",&t);
    int sa , sb;
    LL a[100], b[100] , c[100] , d[100];

    scanf("%d",&sa);
    for(int i = 0 ; i < sa ; i++)
        scanf("%lld%lld",&a[i] , &b[i]);

    scanf("%d",&sb);
    for(int i = 0 ;i<sb ; i++)
        scanf("%lld%lld",&c[i] ,&d[i]);

    printf("%lld\n", b_search(a,b,c,d,t,sa,sb));
    return  0;
}