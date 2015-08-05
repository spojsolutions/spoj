#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int X,Y,sum=0;
        scanf("%d%d",&X,&Y);
        if(X==y||Y==(X-2))
        {
            if(X%2==0&&Y%2==0){
            sum=X+Y;
            printf("%d\n",sum);}
            if(X%2!=0&&Y%2!=0)
            {
            sum=X+Y-1;
            printf("%d\n",sum);
            }
        }
        else
        printf("No Number\n");

    }
    return 0;
}
