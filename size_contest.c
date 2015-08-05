#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,*number,sum=0,i;
    scanf("%d",&n);
    number=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",(number+i));
        if(*(number+i)>0)
        sum=sum+*(number+i);
    }
    printf("%d",sum);
    return 0;
}
