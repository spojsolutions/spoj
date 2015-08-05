#include <stdio.h>
#include <iostream>
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
struct activity
{
	int s,f;
};
#define act struct activity
void mergesort(act a[],int low,int mid,int high,int n)
{
	int i=low,j=mid+1,k=low;
	act temp[n+9];
	while(i<=mid && j<=high)
	{
		if(a[i].f < a[j].f)
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
void partition(act a[],int low,int high,int n)
{
	int m;
	if(low<high)
	{
		m=(low+high)/2;
		partition(a,low,m,n);
		partition(a,m+1,high,n);
		mergesort(a,low,m,high,n);
	}
}
int main()
{
	int t;
	act a[100009];
	scanint(t);
	while(t--)
	{
		int n,i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanint(a[i].s);
			scanint(a[i].f);
		}
		partition(a,0,n-1,n);
		int count=1;
		i=0;
		for(j=1;j<n;j++){
			if(a[j].s>=a[i].f){
				count++;
				i=j;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}