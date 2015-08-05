#include<stdio.h>
int main()
{
	int i;
	int A[100000];
	for(i=0;i<100000;i++)
		A[i]=i;
	for(i=2;i*i<100000;i++)
	{
		if(A[i]>0)
		{
			for(i=A[i];i*i<100000;i=i+i*A[i])
				A[i]=0;
		}
	}
	for(i=2;i<100000;i++)
		if(A[i]!=0)
			printf("%d\n",A[i]);
	return 0;
}