#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define MOD 1000000009
int rank[20][100000];
int SA[100009];
struct tuple
{
	int left , right , pos;
};
void cnt_sort(tuple t[] , int n)
{
	int count[MAX+9];
	memset(count , 0 , sizeof count);
	tuple temp[n+9];
	for(int i = 0 ; i < n ; i++)
		count[t[i].right + 1] ++;

	for(int i = 1 ; i < MAX ; i++)
		count[i] += count[i-1];

	for(int i = 0 ; i < n ; i++)
	{
		temp[count[t[i].right +1 ] - 1] = t[i];
		count[t[i].right + 1]--;
	}

	memset(count , 0 , sizeof count);

	for(int i = 0 ; i < n ; i++)
		count[t[i].left + 1]++;

	for(int i = 1 ; i < MAX ; i ++)
		count[i]+=count[i-1];

	for(int i = n-1 ; i >=0 ; i--)
	{
		t[count[temp[i].left+1] - 1] = temp[i];
		count[temp[i].left + 1 ]--;
	}
}
void suffix_array(int arr[] , int n)
{
	tuple t[n+9];
	for(int i = 0 ; i < n ;i++)
		rank[0][i] = arr[i] + 101;
	for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
	{
		for(int i = 0 ; i < n ; i++)
		{
			t[i].left = rank[stp - 1][i];
			t[i].right = i+cnt < n ? rank[stp-1][i+cnt] : -1;
			t[i].pos = i;
		}
		cnt_sort(t , n);
		for(int i = 0 ; i < n ; i++)
			rank[stp][t[i].pos] = i > 0 && t[i].left == t[i-1].left && t[i].right == t[i-1].right ? rank[stp][t[i-1].pos] : i;
	}
	int pos = ceil(log(n) / log(2));
	for(int i = 0 ; i < n ; i++)
		SA[rank[pos][i]] = i;
}
int lcp_sum(int arr[] , int n)
{
	int sum= 0 , k = 0;
	int ran[n+9];
	memset(ran , 0 , sizeof ran);
	for(int i = 0 ; i < n ; i ++)
		ran[SA[i]] = i;
	for(int i = 1 ; i < n ; i++ , k?k--:0)
	{
		if(ran[i] = n-1)
		{
			k = 0 ;
			continue;
		}
		int j = SA[ran[i]+1];
		while(i+k < n && j+k && arr[i+k] == arr[j+k] ) k++;
		sum = (sum + k)%MOD;
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n ; 
		cin>>n;
		int arr[n+9] , a[n+9];
		for(int i = 0 ; i<n ; i++)
			cin>>a[i];
		for(int i = 1 ; i < n ; i++)
			arr[i-1] = a[i] - a[i-1];
		n--;
		memset(SA , 0 , sizeof SA);
		for(int i = 0 ; i < n ; i++)
		{
			cout<<SA[i];
			//(int j = SA[i] ; j < n ; j++)
			//	cout<<arr[j]<<" ";
			cout<<endl;
		}
		memset(rank , 0 , sizeof rank);
		suffix_array(arr , n);
		cout<<(long long)(n*(n-1))/2 <<endl;
	}
	return 0;
}