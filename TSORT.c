#include<stdio.h>
void merge(int A[],int low,int mid,int high,int n)
{
	int i,l,m,k,temp[n];
	i=low;m=mid+1;l=low;
	while(l<=mid && m<=high)
	{
		if(A[l]<=A[m])
		{
			temp[i]=A[l];
			i++;l++;
		}
		else
		{
			temp[i]=A[m];
			m++;i++;
		}
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++){
			temp[i]=A[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			temp[i]=A[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
		A[k]=temp[k];
}
void partition(int A[],int LB,int UB,int n)
{
	int mid;
	if(LB<UB)
	{
		mid=(UB+LB)/2;
		partition(A,LB,mid,n);
		partition(A,mid+1,UB,n);
		merge(A,LB,mid,UB,n);
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	int A[t];
	for(i=0;i<t;i++)
		scanf("%d",&A[i]);
	partition(A,0,t-1,t);
	for(i=0;i<t;i++)
		printf("%d\n",A[i]);
	return 0;
}