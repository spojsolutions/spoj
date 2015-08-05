#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int num;
        scanf("%lld",&num);
        long long int i,sum=1;
        for(i=2;i<=num/2;i++)
        {
            if(num%i==0)
            sum=sum+i;
        }
        printf("%lld",sum);
    }
    return 0;
}
