/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 02 October 2015 (Friday) 19:07
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
void mul(ULL a[][2] , ULL b[][2] , ULL MOD)
{
    ULL res[2][2];
    memset(res , 0 , sizeof res);
    for(int i = 0 ; i < 2 ; i ++)
        for(int j = 0 ; j < 2 ; j++)
            for(int k = 0 ; k < 2 ; k++)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            a[i][j] = res[i][j];
}
ULL  power( ULL  n , ULL MOD)
{
    ULL  fib[2][2] = { {1 , 1} , { 1 , 0}},temp[2][2] = { {1 , 0 } , { 0 , 1}};
    while(n)
    {
        if(n&1)
            mul(temp , fib , MOD);
        mul(fib , fib , MOD);
        n>>=1;
    }
    return temp[0][1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k , n , MOD;
        cin>>k>>n>>MOD;
        ULL ans = n;
        while(k--) {
        	ans = power(ans , MOD);
        }
        cout<<ans<<endl;
    }
    return 0;
}