#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double R1,R2,R3,K1,K2,K3,K4,r;
        scanf("%lf%lf%lf",&R1,&R2,&R3);
        K1=1/R1;K2=1/R2;K3=1/R3;
        K4=K1+K2+K3+2*sqrt((K1*K2)+(K2*K3)+(K1*K3));
        r=1/K4;
        printf("%0.6lf\n\n",r);
    }
    return 0;
}
