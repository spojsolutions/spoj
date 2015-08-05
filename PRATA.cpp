#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long 
int n;
ULL get_num(int a,ULL sum)
{
    ULL d = (ULL)sqrt(a*a + 8*a*sum);
    d-=a;
    return d / (2*a);
}
int check(int arr[],ULL chef,ULL tim)
{
    ULL count = 0;
    for(ULL i =0 ;i<chef;i++)
    {
        count += get_num(arr[i],tim);
        if(count >= n)
            return 1;
    }
    return 0;
}
ULL binary_search(int arr[],ULL chef,ULL max)
{
    ULL low = 1,mid,high = max;
    while(low<high)
    {
        mid = (low+high)>>1;
        if(check(arr,chef,mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int chef;
        scanf("%d%d",&n,&chef);
        int arr[chef+9],ma = -1;
        for(int i = 0;i<chef ; i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+chef);
        ULL res = binary_search(arr,chef,(ULL)10*n*(n+1)/2);
        printf("%lld\n",res);
    }
    return 0;
}