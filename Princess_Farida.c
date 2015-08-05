#include<stdio.h>
#include<stdlib.h>
long long int FindMaxSum(long long int arr[], int n);
int main()
{
    int t=1,n;
    scanf("%d",&n);
    while(t<=n)
    {
        int number;
        scanf("%d",&number);
       long long int *coins,sum;
        coins=(long long int *)malloc(number*sizeof(long long int));
        int i;
        for(i=0;i<number;i++)
        scanf("%lld",(coins+i));
        sum=FindMaxSum(coins , number);
       printf("Case %d: %lld\n",t,sum);

        t++;
    }
    return 0;
}
long long int FindMaxSum(long long int arr[], int n)
{
  long long int incl = arr[0];
  long long int excl = 0;
  long long int excl_new;
  int i;

  for (i = 1; i < n; i++)
  {

     excl_new = (incl > excl)? incl: excl;


     incl = excl + arr[i];
     excl = excl_new;
  }


   return ((incl > excl)? incl : excl);
}
