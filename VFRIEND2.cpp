#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
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
/*long long temp[10000009];
void mergesort(long long a[],int low,int mid,int high,int n)
{
	int i=low,k=low,j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i] > a[j])
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
void partition(long long a[],int low,int high,int n)
{
	int mid;
	if(low<high)
	{
		mid=(low + high)/2;
		partition(a,low,mid,n);
		partition(a,mid+1,high,n);
		mergesort(a,low,mid,high,n);
	}
}*/
int main()
{
	int t;
	scanint(t);
	while(t--)
	{
		int n,a,b,c,m;
		scanint(n);
		scanint(a);
		scanint(b);
		scanint(c);
		scanint(m);
		long long s=0,ksum=0,*sum,*arr,*temp,i,j,x=0,flag=1;
		arr=(long long *)calloc(20000009,sizeof(long long));
		temp=(long long *)calloc(20000009,sizeof(long long));
		arr[1]=c;
		sum=(long long *)calloc(n+9,sizeof(long long));
		s+=arr[1];
		for(i=2;i<=n;i++)
		{
			x=(a*x + b)%m;
			temp[x+c]++;
			s=s+x+c;
		}
		if(s%2==0)
		{
			//partition(arr,1,n,n+1);
			int k=1;
			for(i=20000009;i>=0;i--)
				if(temp[i])
				{
					while(temp[i]--)
					{
						arr[k++]=i;
					}
				}
			sum[0]=0;
			flag=1;
			for(i=1;i<=n;i++){
				sum[i]=sum[i-1]+arr[i];
			}
			for(i=1;i<=n;i++)
			{
				ksum=0;
				for(j=i+1;j<=n;j++)
					ksum+=min(arr[j],i);
				if( sum[i] > (i*(i-1) + ksum))
				{
					flag=0;
					break;
				}
			}
			if(flag)
				printf("HAPPY\n");
			else
				printf("SAD\n");
		}
		else
			printf("SAD\n");
	}
}