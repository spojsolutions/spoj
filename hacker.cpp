#include <bits/stdc++.h>
using namespace std;
bool compare(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],save[n];
	long long avg = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		save[i] = arr[i];
	}
	int m = -1;
	long long profit=0;
	for(int i= n-1;i>=0;i--)
	{
		m = max(m , arr[i]);
		profit+=m - arr[i];
	}
	printf("%lld\n",profit);
	return 0;
}