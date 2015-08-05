#include <stdio.h>
#include <iostream>
#include <algorithm>
int temp[100009];
using namespace std;
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void mergesort(int a[],int low,int mid,int high)
{
	int i=low,k=low,j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++]; 
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];
	for(i=low;i<=high;i++)
		a[i]=temp[i];
}
void partition(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low + high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergesort(a,low,mid,high);
	}
}
int main()
{
	int n,i,j,count=0;
	scanint(n);
	int q[n+9],ni[n+9];
	for(i=0;i<n;i++)
		scanint(q[i]);
	for(i=0;i<n;i++)
		scanint(ni[i]);
	partition(q,0,n-1);
	partition(ni,0,n-1);
	i=n-1;
	j=n-1;
	while(i>=0 && j>=0)
	{
		if(ni[i]>q[j])
		{
			count++;
			i--;
			j--;
		}
		else
			j--;
	}
	printf("%d",count);
	return 0;
}