#include<stdio.h>
void quicksort(int A[],int LB,int UB)
{
	int i,j,pivot,temp;
	if(LB<UB)
	{
		pivot=LB;
		i=LB;
		j=UB;
		while(i<j)
		{
			while(A[i]<=A[pivot]&&i<UB)
				i++;
			while(A[j]>A[pivot])
				j--;
			if(i<j)
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
		temp=A[j];
		A[j]=A[pivot];
		A[pivot]=temp;
		quicksort(A,LB,j-1);
		quicksort(A,j+1,UB);
	}
}
int main()
{
	int test, N, M, ans, i ,men[1001], women[1001];
    scanf("%d",&test);
    while (test--) 
    {
         ans = 0;
         scanf("%d",&N);

         for(i=0;i<N;i++)
                 scanf("%d",&men[i]);

         for(i=0;i<N;i++)
                 scanf("%d",&women[i]);

         quicksort(men,0,N-1);
         quicksort(women,0,N-1);

         for(i=0;i<N;i++)
                 ans += men[i] * women[i];
         printf("%d\n", ans);
    }
        return 0;
}