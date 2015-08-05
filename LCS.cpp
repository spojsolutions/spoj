#include <bits/stdc++.h>
using namespace std;
#define MAX 500001
int rank[20][MAX];
struct tuple
{
	int left,right,pos;
};
bool compare(const tuple &a, const tuple &b)
{
	return a.left == b.left ? a.right < b.right : a.left < b.left;
}
int * suffix_array(char s[],int n)
{
	int *arr;
	arr = (int *)calloc(n+9,sizeof(int));

	for(int i=0;i<n;i++)
	{
		if(s[i] == '#')
			rank[0][i] = 0;
		else
			rank[0][i] = s[i] - 96;
	}

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
	return arr;
}
int LCP(int i, int j,int n)
{
	int res = 0,pos = ceil(log(n)/log(2));
	for(int stp = pos ; stp>=0 && i < n && j < n; stp--)
	{
		if(rank[stp][i] == rank[stp][j] )
		{
			res += 1<<stp;
			i += 1<<stp;
			j += 1<<stp;
		}
	}
	return res;
}
int * LCParray(int sa[] , int n)
{
	int *arr;
	arr = (int *)calloc(n+9,sizeof(int));
	arr[0] = INT_MAX;
	for(int i = 1;i < n ; i++)
		arr[i] = LCP(sa[i-1],sa[i],n);
	return arr;
}
int main()
{
	char s[700009],t[300009];
	scanf("%s",s);
	strcpy(t,s);
	int length = strlen(s);
	strrev(t);
	strcat(s,"#");
	strcat(s,t);
	int n = strlen(s);
	int *sa,*lcp;
	sa = suffix_array(s,n);
	lcp = LCParray(sa,n);
	int ma =-1;
	for(int i = 1;i<n;i++)
	{
		if((sa[i-1] < length && sa[i] > length) || (sa[i-1] > length && sa[i] < length)){
			ma = max(ma,lcp[i]);
		}
	}
	printf("%d\n",ma);
	return 0;
}