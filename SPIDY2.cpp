#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+9];
	long long  compute[n+9];
	compute[0] = 0;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=1;i<n;i++)
	{
		int cnt = 1;
		compute[i] = 99999999999LL;
		while((i-cnt)>=0){
			compute[i] = min(compute[i-cnt] + abs(arr[i] - arr[i-cnt]) ,compute[i]);
			cnt<<=1;
		}
	}
	cout<<compute[n-1]<<endl;
	return 0;
}