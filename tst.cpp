/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 26 September 2015 (Saturday) 00:26
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ULL unsigned long long 
void mul(ULL a[][2] , ULL b[][2])
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
ULL  power( ULL  n)
{
    ULL  fib[2][2] = { {3 , 1} , { 0 , 1}},temp[2][2] = { {1 , 0 } , { 0 , 1}};
    while(n)
    {
        if(n&1)
            mul(temp , fib);
        mul(fib , fib);
        n>>=1;
    }
    ULL res = ((temp[0][0]*6)%MOD + temp[0][1])%MOD;
    return res;
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
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ULL n ;
        scanf("%llu",&n);
        if(n == 2){
        	printf("%d\n" , 4);
        	continue;
        }
        printf("%llu\n",(power(n-2) - pow_mod(2 , n-1) + MOD)%MOD);
    }
    return 0;
}