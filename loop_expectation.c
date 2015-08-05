#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int num;
        long long int j;
        double  result=1,k=1,n=1;
        scanf("%lld",&num);
        for(j=2;j<=num;j++)
        {
            k=k*(j-1);
            result=(j*result+k);
            n=n*j;
        }
        printf("%lf",result/n);
    }
    return 0;
}
