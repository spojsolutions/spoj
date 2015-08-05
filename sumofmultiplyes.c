#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int num,sum=0;
        long long int  a=0,b=0,c=0;
        scanf("%lld",&num);
        a=num/3;
        b=num/5;
        c=num/15;
        if(num%3==0)
        a=a-1;
        if(num%5==0)
        b=b-1;
        if(num%15==0)
        c=c-1;
        sum=(a)*(6+(a-1)*3)+(b)*(10+(b-1)*5)-(c)*(30+(c-1)*15);
        sum=sum/2;
        printf("%lld",sum);
    }
    return 0;
}
