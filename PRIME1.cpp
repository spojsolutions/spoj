#include <bits/stdc++.h>
using namespace std;
vector<int > prime;
bool check[50009];
int keep = 1;
void pre()
{
    check[1 ] = 1;
    for(int i = 3 ; i <=224 ; i+=2){
        if(!check[i]){
            for(int j = i*i ; j<= 50000 ; j+=2*i)
                check[j] = true;
        }
    }
    prime.push_back(2);
    keep=1;
    for(int i = 3 ; i<= 50000 ; i++)
        if(check[i] == false && (i&1))
            prime.push_back(i) , keep++;
}
bool seg[1000009];
int main()
{
    int t;
    scanf("%d",&t);
    pre();
    while(t--)
    {
        int a , b;
        scanf("%d%d",&a , &b);
        if(b <= 50000){
            if(a<=2)
                printf("2\n");
            for(int i = a ; i<= b ; i++){
                if(check[i] == false && (i&1))
                    printf("%d\n", i);
            }
            continue;
        }
        memset(seg , 0 , sizeof seg);
        for(int i = 0; prime[i]*prime[i] <= b ; i++)
        {
            int begin = a/prime[i];
            begin *= prime[i];
            for(int j = begin ; j<= b ; j+= prime[i]){
                if(j < a)
                    continue;
                seg[j - a] = true;
            }
        }
        for(int i  = 0 ; prime[i]*prime[i] <= b ; i++){
            if(prime[i]>= a && prime[i]<=b)
                printf("%d\n",prime[i]);
        }
        for(int i = a==1?1:0 ; i < b-a+1 ; i++)
            if(seg[i]==0)
                printf("%d\n", i+a);
    }
    return 0;
}
