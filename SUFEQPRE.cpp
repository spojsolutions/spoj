#include <bits/stdc++.h>
using namespace std;
inline int min(int a , int b)
{
    if(a<b)
        return a;
    return b;
}
int Z_function(char s[] , int n)
{
    int z[n+9] , count = 0;
    memset(z , 0 , sizeof z);
    int l=0,r=0;
    z[0] = n;
    for(int i=1;i<n;i++)
    {
        if(i<=r)
            z[i] = min(r-i+1 , z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if(i+z[i]-1 > r)
            l = i, r = i+ z[i] - 1;
        if(z[i] == n - i)
            count ++;
    }
    return count;
}
int main()
{
    int t , n , j = 1;
    char s[1000009];
    scanf("%d ",&t);
    while(t--)
    {
        gets(s);
        n = strlen(s);
        printf("Case %d: %d\n",j,Z_function(s , n));
        j++;
    }
    return 0;
}