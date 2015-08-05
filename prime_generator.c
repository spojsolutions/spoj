#include<stdio.h>
int main()
{
    long long int initial , final,i,j,count,k=0;
    int divisor,flage=0;
    scanf("%lld%lld%d",&initial,&final,&divisor);
    for(i=initial;i<=final;i++)
    {
        count=0;
        while(i/divisor!=0)
        {
            count++;
            i=i/divisor;
        }
        if(count+1==divisor){
        k++;
        }
    }
    printf("%d",k);
    return 0;

}
