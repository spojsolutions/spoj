#include <bits/stdc++.h>
using namespace std;
int *Z_function(char s[])
{
    int *z;
    z = (int*)calloc((strlen(s)+9),sizeof(int));
    int l=0,r=0,n = strlen(s);
    z[0] = n;
    for(int i=1;i<n;i++)
    {
        if(i<=r)
            z[i] = min(r-i+1 , z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if(i+z[i]-1 > r)
            l = i, r = i+ z[i] - 1;
    }
    return z;
}
int main()
{
    int n;
    while(1)
    {
        char s[1000009];
        scanf("%d",&n);
        scanf("%s",s);
        if(n==-1)
            return 0;
        int *z;
        int size = strlen(s);
        if(n<size)
        {
            printf("0\n");
            continue;
        }
        z = (int*)calloc((size+9),sizeof(int));
        z = Z_function(s);
        int m = 0;
        for(int i=1;i<size;i++)
        {
            if(i+z[i] == size)
                m = max(m , z[i]);
        }
        int total;
        total = (n-m)/(size - m);
        printf("%d\n",total);
    }
    return 0;
}