#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double num,sum,a=0.5;
        scanf("%lf",&num);
        sum=a*(a-(1/(num+1))+(1/(num+2)))+0.5;
        printf("%.11lf",sum);
    }
    return 0;
}
