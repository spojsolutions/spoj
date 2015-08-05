#include<stdio.h>
int main()
{
    long int result=0,sq_num,count=0;
    int i=1,j=1;
    scanf("%ld",&sq_num);
    for(i=1;i*i<=sq_num;i++)
    {
        j=i;
    while(result<sq_num)
    {
        result=i*j;
        if(result <= sq_num){
        j++;count++;}
        else
        break;
    }
    result=0;
    }
    printf("%ld",count);
    return 0;
}
