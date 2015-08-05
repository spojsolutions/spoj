#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,max_cur,max_till,start,end,temp,A[10]={1,-2,-7,9,4,-7,10,-9,12,8};
	max_cur=A[0];
	max_till=A[0];
	for(i=1;i<10;i++)
	{
		if(max_cur<0)
		{
			max_cur=A[i];
			start=i;
		}
		else
			max_cur+=A[i];
		if(max_till<max_cur)
		{
			max_till=max_cur;
			end=i;
		}
	}
	printf("%d\n",max_till);
	for(i=start;i<=end;i++)
		printf("%d\t",A[i]);
	return 0;
}