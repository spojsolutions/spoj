#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int num;
        scanf("%d",&num);
        int A[num],avg=0;
        int i;
        for(i=0;i<num;i++)
        {
            scanf("%d",&A[i]);
            avg=avg+A[i];
        }
        printf("%d\n",(avg/num));
    }
    return 0;
}
