//TLE O(n log^2 n + nlogn)

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define LL long long 
int rank[20][MAX];
int arr[100000],cum[100000],lcp[100000];
struct tuple
{
	int left,right,pos;
};
bool compare(const tuple &a, const tuple &b)
{
	return a.left == b.left ? a.right < b.right : a.left < b.left;
}
void suffix_array(char s[],int n)
{

	for(int i=0;i<n;i++)
		rank[0][i] = s[i] - 97;

	tuple t[n+9];


	for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
	{
		for(int i=0;i<n;i++)
		{
			t[i].left = rank[stp-1][i];
			t[i].right = i+cnt < n ? rank[stp-1][i + cnt] : -1;
			t[i].pos = i;
		}
		sort(t,t+n,compare);
		for(int i=0;i<n;i++)
			rank[stp][t[i].pos] = i > 0 && t[i-1].left == t[i].left && t[i-1].right == t[i].right ? rank[stp][t[i-1].pos] : i;
	}
	int pos = ceil(log(n)/log(2));
	for(int i = 0;i<n;i++)
		arr[rank[pos][i]] = i;
}
int LCP(int i,int j,int n)
{
	int count = 0;
	if(i == j)
		return n - i;
	for(int stp = ceil(log(n)/log(2)) ; stp >= 0 && i < n && j < n ; stp --)
		if(rank[stp][i] == rank[stp][j])
		{
			count += 1<<stp;
			i += 1<<stp;
			j += 1<<stp;
		}
	return count;
}
void lcpArray(int sa[],int n)
{
	lcp[0] = 0;
	for(int i = 1;i<n;i++)
		lcp[i] = LCP(sa[i - 1] , sa[i],n);
	
}
int main()
{
	char s[100000];
	scanf("%s",s);
	int  n = strlen(s);
	suffix_array(s,n);
	lcpArray(arr , n);
	cum[0] = n - arr[0];
	for(int i = 1;i < n;i++){
		cum[i] = cum[i-1] + (n - arr[i] - lcp[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a ;
		scanf("%d",&a);
		int pos ;
		for(int i = 0; i<n ; i++)
			if(cum[i] >= a)
			{
				pos = i;
				break;
			}
		int i , j;
		for(i = arr[pos] ,j = 0 ; j <  lcp[pos] ; j++ , i++)
			printf("%c",s[i]);
		for(int j = 0 ; j< a - cum[pos-1] ; j++,i++)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}