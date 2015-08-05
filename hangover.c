#include<stdio.h>
int main()
{
    while(1)
    {
        float num;
        scanf("%f",&num);
        if(num==0.00)
        break;
        float i=2,a=1;
        float sum=0;
        int count=0;
        while(sum<num)
        {
            sum=sum+a/i;
            i++;
            count++;
        }
        printf("%d card(s)\n",count);
    }
    return 0;

}
