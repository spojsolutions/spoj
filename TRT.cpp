#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int arr[2009];
int calculate(int start , int end , int year)
{
    if(start > end)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];
    return (dp[start][end] = max(calculate(start + 1 , end , year+1) + year * arr[start] , calculate(start, end - 1 , year+1) + arr[end]*year));
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(dp , -1 , sizeof dp);
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);
    printf("%d\n",calculate(0 , n-1 , 1));
    return 0;
}