#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long 
ULL solve(int a,ULL sum)
{
    ULL d = (ULL)sqrt(a*a + 8*a*sum);
    d-=a;
    return d / (2*a);
}
ULL calculate(ULL a[], ULL t , int sz)
{
    ULL total = 0;
    for(int i = 0 ; i < sz ; i++)
        total += solve(a[i], t);
    return  total;
}
ULL b_search(ULL a[] , ULL b[], LL t ,int sa, int sc)
{
    ULL low = 1 , high = t , mid , lhalf = 0 , rhalf , ma = 0 , m2;
    while(low < high)
    {
        mid = (low + high)>>1;
        lhalf = calculate(a,mid,sa);
        rhalf = calculate(b,t - mid , sc);
        if(lhalf <= rhalf){
            low = mid + 1;
            ma = max(lhalf , ma);
        }
        else if(lhalf > rhalf)
            high = mid;
    }
    return ma;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ULL p , n , m ;
        cin>>p;
        cin>>n>>m;
        ULL a[n+9];
        for(int i = 0 ; i  < n ; i ++)
            cin>>a[i];
        ULL b[m+9];
        for(int i = 0 ; i < m ; i++)
            cin>>b[i];
        cout<<b_search(a,b,p,n,m)<<endl;
    }
    return 0;
}