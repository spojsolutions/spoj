#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c))
    {
        if(a==0&&b==0&&c==0)
        break;
        int d=b-a;
        long int e=b/a;
        if(d==c-b)
        printf("AP %d\n",c+d);
        else
        printf("GP %ld\n",e*c);
    }
    return 0;
}
