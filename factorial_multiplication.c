#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int *length;
    int num;
    int i;
    int *fact;
    scanf("%d",&num);
    length=(int *)malloc(sizeof(int));
    fact=(int *)malloc(MAX*sizeof(int));
	*length=0;
    fact[0]=1;
	for(i=2;i<=num;i++)
	{
		long j,r=0;
        int arr[MAX];
		 for(j=0;j<=*length;j++){
                arr[j]=*(fact+j);
             }

    for(j=0;j<=*length;j++){
         *(fact+j) = (arr[j]*i + r)%10;
         r = (arr[j]*i + r)/10;
    }
    if(r!=0){
         while(r!=0){
             *(fact+j)=r%10;
             r= r/10;
             j++;
         }
    }
    *length = j-1;

	}

    for(i=*length;i>=0;i--){
         printf("%d",*(fact+i));
    }
   printf("\n");
    }
    return 0;
}
