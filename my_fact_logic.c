#include<stdio.h>
#include<stdlib.h>
#define MAX 200000
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int *fact;
        long int i;
        long int *position;
        long long int num;
        scanf("%lld",&num);
        fact=(int *)malloc(MAX*sizeof(long long int));
        position=(int *)malloc(sizeof(long int));
        *position=0;
        fact[0]=1;
        for(i=2;i<=num;i++)
        {
            long carry=0,j;
            long long int arr[MAX];
            for(j=0;j<=*position;j++)
            {
                arr[j]=*(fact+j);
                *(fact+j)=(arr[j]*i+carry)%10;
                carry=(arr[j]*i+carry)/10;
            }
            while(carry!=0)
            {
                *(fact+j)=carry%10;
                carry=carry/10;
                j++;
            }
            *position=j-1;
        }
        long long count = 0;
        for(i=*position;i>=0;i--){
        printf("%lld",*(fact+i));count++;}
        printf("\n%lld",count);
        free  (fact);
        free  (position);
    }

    return 0;

}
