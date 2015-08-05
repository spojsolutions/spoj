#include<stdio.h>
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long child,sum=0;

        scanf("%lld",&child);
        long long A[child];
        long long int i;
        for(i=0;i<child;i++){
        scanf("%ld",&A[i]);
        sum=sum+A[i];
        }
        if(sum==0)
        printf("NO\n");
        else if(sum%child==0)
        printf("YES\n");
        else
        printf("NO\n");

    }
    return 0;
}
