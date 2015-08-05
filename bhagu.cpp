
#include <stdio.h>
#include <math.h>
int main(void)
{
    float n;
    do
    {
        printf("O hai! How much change is owed?\n");
        scanf("%f",&n);
    }while(n < 0.00);
    
    double coins = 0.0;
    while(n > 0.00)
    {
        if(n >= 0.25)
        {
            coins +=floor( n/0.25);
            n -= ((int) (n/0.25))*0.25;
            printf("%lf\n",coins);
            printf("%f\n",n);
        }
        else if(n >= 0.10 && n < 0.25)
        {
            coins += floor(n/0.10);
            n -= ((int) (n/0.10))*0.10;
            printf("%lf\n",coins);
            printf("%f\n",n);
        }
        else if(n >= 0.05 && n < 0.10)
        {
            coins += floor(n/0.05);
            n -= ((int) (n/0.05))*0.05;
            printf("%lf\n",coins);
            printf("%f\n",n);
        }
        else
        {
            coins += (n*100.0);
            n = 0.00;
            printf("%lf\n",coins);
            printf("%f\n",n);
        }
    }
    printf("%0.0lf\n",coins);
}