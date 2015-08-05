#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int sum=0,a,b,m,c;
        int i,n;
        scanf("%lld%lld%d%lld",&a,&b,&n,&m);
        if(n==1)
        sum=a;
        if(n==2)
        sum=a+b;
        if(n>2)
        {
            sum=a+b;
        for(i=3;i<=n;i++)
        {
            c=a+b;
            sum=sum+c;
            a=b;
            b=c;


        }
        }
        printf("%lld",sum%m);
    }
    return 0;
}
