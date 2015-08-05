#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long 
int p[1000009];
int prime[100000];
int pre()
{
    for(int i = 3 ; i * i <= 1000000 ; i+=2){
        if(!p[i])
            for(int j = i*i ; j <= 1000000 ; j+=i)
                p[j] = 1;
    }
    prime[0] = 2;
    int k = 1;
    for(int i = 3 ; i <= 1000000 ; i+=2)
        if(!p[i])
            prime[k++] = i;
    return k;
}
int main()
{
    int t;
    int len = pre();
    cin>>t;
    for(int test = 1 ; test <= t ; test++){
        int n;
        scanf("%d",&n);
        int arr[n+9];
        for(int i =0 ; i < n ; i++)
            scanf("%d",&arr[i]);
        int a[len+9];
        memset(a , 0 , sizeof a);
        for(int i = 0 ; i < n ; i ++){
            LL temp = arr[i];
            for(int j = 0 ; (LL)prime[j] * prime[j] <= temp ; j++){
                int count = 0;
                while(temp%prime[j] == 0){
                    temp/=prime[j];
                    count++;
                }
                a[j] = max(a[j] , count);
            }
            if(temp > 1){
                int pos = lower_bound(prime , prime + len , temp) - prime;
                a[pos] = max(a[pos] , 1);
            }
        }
        LL res = 1;
        for(int i = 0 ; i < len ; i++)
        {
            int temp = a[i] ; 
            while(temp--)
                res = (res * prime[i])%MOD;
        }
        printf("Case %d: %lld\n",test ,res);
    }
    return 0;
}