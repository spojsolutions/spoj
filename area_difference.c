#include<stdio.h>
int main()
{
	int n,i,t;
	scanf("%d",&n);
	char A[n];
	for(i=0;i<n;i++)
	scanf("%c",&A[i]);
	int l=0,r=n,lo=0;

	while(1)
	{
		while((A[lo]<=A[r])&&lo!=r)
		{
			r=r-1;
		}
			if(l==r)
			break;
			if(A[lo]>A[r])
			{
				t=A[lo];A[lo]=A[r];
				A[r]=t;
				lo=r;
			}
			while((A[l]<=A[lo])&&l!=lo)
			l=l+1;
			if(lo==l)
			break;
			if(A[l]>A[lo])
			{
				t=A[lo];A[lo]=A[l];A[l]=t;
				lo=l;
			}

	}for(i=0;i<n;i++)
	printf("%c",A[i]);
	return 0;

}
