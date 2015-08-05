#include<stdio.h>
int main()
{
    int t;
    scanf("%s",&t);
    while(t--)
    {
        int initial,final,total=0,temp;
        scanf("%d%d",&initial,&final);
        int i;
        if(initial<=final)
        temp=initial;
        else
        temp=final;
        for(i=1;i<=temp;i++)
        if(initial%i==0&&final%i==0)
        total++;
        printf("%d",total);
    }
    return 0;
}
