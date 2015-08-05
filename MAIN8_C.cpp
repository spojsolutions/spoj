#include <bits/stdc++.h>
using namespace std;
bool check(int arr[] , int src , int check , int n)
{
	long long count = 0;
	if(src == 0)
		return true;
	for(int i = 0 ; i < n ; i ++)
		count += arr[i] / src ;
	if(count >= check)
		return true;
	else
		return false;
}
int b_search(int arr[] , int n , int k)
{
	int low = 0 , high = 2000000000 ,mid , ma = 0;
	while(low < high)
	{
		mid = (low + high )>>1;
		if(check(arr , mid , k , n)){
			ma = max(ma , mid);
			low = mid + 1;
		}
		else
			high = mid;
	}
	return ma;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n , k;
		scanf("%d%d",&n , &k);
		int arr[n+9];
		for(int i = 0 ; i < n ; i++)
			scanf("%d",&arr[i]);
		printf("%d\n", b_search(arr , n , k));
	}
	return 0;
}