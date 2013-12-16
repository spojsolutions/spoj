#include<stdio.h>
void merge(long long A[],long long low,long long mid,long long high,long long n)
{
	long long i,l,m,k,temp[n];
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
void partition(long long A[],long long LB,long long UB,long long N)
{
	long long mid;
	if(LB<UB)
	{
		mid=(UB+LB)/2;
		partition(A,LB,mid,N);
		partition(A,mid+1,UB,N);
		merge(A,LB,mid,UB,N);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long N,i;
		scanf("%lld",&N);
		char NAME[10000];
		long long P_R[N],SUM=0;
		for(i=0;i<N;i++)
			scanf("%s%lld",NAME,&P_R[i]);
		partition(P_R,0,N-1,N);
		for(i=0;i<N;i++)
		{
			if((i+1)-P_R[i]<0)
				SUM=SUM+((-1)*((i+1)-P_R[i]));
			else
				SUM=SUM+((i+1)-P_R[i]);
		}
		printf("%lld\n",SUM);
	}
	return 0;
}
