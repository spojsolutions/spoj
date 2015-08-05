#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <bitset>
using namespace std;
inline void scanint(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
 
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
 

    for(; c>47 && c<58 ; c = getchar_unlocked()) {

        x = (x<<1) + (x<<3) + c - 48;

    }
 
    if(neg)

        x = -x;

}
class job
{
public:
	int deadline;
	int profit;
};
void mergesort(job a[],int low,int mid,int high)
{
	job temp[10009];
	int i=low,k=low,j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i].profit >=a[j].profit)
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
void partition(job a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergesort(a,low,mid,high);
	}
}
int main()
{
	int n;
	scanint(n);
	int i,max=-1,k;
	bitset<10009>p;
	job j[n+9];
	for(i=0;i<n;i++)
	{
		scanint(j[i].profit);
		scanint(j[i].deadline);
	}
	partition(j,0,n-1);
	int total=0;
	for(i=0;i<n;i++)
	{
		if(!p.test(j[i].deadline)){
			p.set(j[i].deadline,1);
			total+=j[i].profit;
		}
		else
		{
			for(k=j[i].deadline - 1;k>=1;k--)
			{
				if(!p.test(k))
				{
					p.set(k,1);
					total+=j[i].profit;
					break;
				}
			}
		}
	}
	printf("%d\n",total);
	return 0;
}
