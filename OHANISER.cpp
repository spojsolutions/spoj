#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
LL pow_mod(int n)
{
    LL a = 1 , p = 2;
    while(n)
    {
        if(n&1)
            a = (a*p)%MOD;
        p = (p*p)%MOD;
        n>>=1;
    }
    return a;
}
int main()
{
    int t , j = 1;
    cin>>t;
    while(t--)
    {
        LL n;
        cin>>n;
        if(n==1)
        {
            cout<<"Case "<<j<<": "<<1<<endl;
            j++;
            continue;
        }
        if(n == 2)
        {
            cout<<"Case "<<j<<": "<<3<<endl;
            j++;
            continue;
        }
        cout<<"Case "<<j<<": "<<((n+1) * (pow_mod(n-2)))%MOD<<endl;
        j++;
    }
    return 0;
}