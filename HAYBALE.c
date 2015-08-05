#include<stdio.h>
#include<stdlib.h>
void quicksort(int A[],int ,int );
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int *A,*T,low,high,i,count=0,median;
	A=(int *)malloc((N+1)*sizeof(int));
	T=(int *)malloc((N+1)*sizeof(int));
	for(i=0;i<K;i++)
	{
		scanf("%d%d",&low,&high);
		T[low]+=1;
		T[high]-=1;
	}
	median=N/2+1;
	for(i=1;i<=N;i++)
	{
		count+=T[i];
		A[i]=count;
	}
	quicksort(A,1,N);
	printf("%d\n",A[median]);
	return 0;
}
void quicksort(int x[],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j)
         {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j)
             {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}