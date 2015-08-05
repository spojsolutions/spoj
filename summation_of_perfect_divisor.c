#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    long long int num,result=0;
    scanf("%lld",&num);
    long int i;
    for(i=2;i*i<num;i++)
    {
        if(num%i==0)
        result=result+i+num/i;
    }
    printf("%lld",result+1);
    }
    return 0;
}
