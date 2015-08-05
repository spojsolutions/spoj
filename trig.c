#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long unsigned num,sum;
        scanf("%llu",&num);
        if(num%2==0)
        sum=(num*(num+2)*((2*num)+1))/8;
        else
        sum=((num*(num+2)*((2*num)+1))-1)/8;
        printf("%llu\n",sum);
    }
    return 0;
}
