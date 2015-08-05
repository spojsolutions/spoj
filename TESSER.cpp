#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
ULL hash[100009];
#define MU 123
void preHash(char str[] , int n)
{
    hash[n] = 0;
    for(int i = n-1 ; i>=0 ; i--)
        hash[i] = hash[i+1]*MU + str[i] - 65;
}
void solve(char str[] ,char pattern[] , int n , int m)
{
    ULL phv = 0;//hash value for pattern strings
    ULL multiplier = 1;
    for(int i = m-1 ; i>=0 ; i--){
        phv = phv*MU + pattern[i] - 65;
        multiplier = multiplier*MU;
    }
    preHash(str , n);
    int flag = 0;
    for(int i = 0 ; i < n - m + 1 ; i++)
        if(hash[i] - multiplier*hash[i+m] == phv)
        {
            flag = 1;
            break;
        }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n+9];
        for(int i=0 ; i < n ; i++)
            scanf("%d",&arr[i]);
        char str[n+9];
        for(int i = 1 ; i < n ; i++)
            if(arr[i] == arr[i-1])
                str[i-1] = 'E';
            else if(arr[i] > arr[i-1])
                str[i-1] = 'G';
            else
                str[i-1] = 'L';
        n--;
        char pattern[n+9];
        scanf("%s",pattern);
        int m = strlen(pattern);
        solve(str , pattern , n , m);
    }
    return 0;
}