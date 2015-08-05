#include <bits/stdc++.h>
using namespace std;
#define LL long long 
#define MAX 100001
LL tree[100009];
LL read(int pos)
{
    LL res = 0;
    while(pos)
    {
        res += tree[pos];
        pos -= (pos & -pos);
    }
    return res;
}
void update(int pos , int val)
{
    while(pos<=MAX)
    {
        tree[pos] += val;
        pos +=(pos & -pos);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n+9] , hold[n+9] ;
        for(int i = 0; i < n ; i++){
            scanf("%d",&arr[i]);
            hold[i] = arr[i];
        }
        sort(arr,arr+n);
        for(int i = 0; i < n ; i++)
        {
            int pos = lower_bound(arr , arr + n , hold[i]) - arr;
            hold[i] = pos;
        }
        LL sum = 0;
        memset(tree, 0 , sizeof tree);
        for(int i = 0; i < n ; i++)
        {
            sum += read(hold[i]);
            update(hold[i] + 1 , arr[hold[i]]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}