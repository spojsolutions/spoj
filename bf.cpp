#include <bits/stdc++.h>
using namespace std;

long long maxSubArraySum(int a[], int size)
{
    long long max_so_far = a[0], i;
   long long  curr_max = a[0];
 
   for (i = 1; i < size; i++)
   {
        curr_max = max((long long)a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
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
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);

		printf("%lld\n",maxSubArraySum(arr,n));
	}
	return 0;
}