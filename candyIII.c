#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int B,i,sum=0;
        scanf("%d",&B);
        int C[B];
        for(i=0;i<B;i++)
        {
        scanf("%d",C+i);
        sum=sum+*(C+i);
        }
        if(sum%B==0)
        printf("YES");
        else
        printf("NO");
    }
    return 0;
}
