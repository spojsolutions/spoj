#include<stdio.h>
int main()
{
    int a=10;
    while(a--)
    {
        long long int number;
        scanf("%lld",&number);
        long long int sum=0;
        int i;
        for(i=2;i<=4;i++)
        sum=sum+number/i;
        if(sum>number)
        printf("%lld\n",sum);
        else
        printf("%lld\n",number);
    }
    return 0;
}
