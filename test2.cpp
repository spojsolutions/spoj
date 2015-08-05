#include<stdio.h>
main()
{
    int n,k=0;
    scanf("%d",&n);
    while(k<n)
    {
    long long unsigned x,y,b,z,e,r,c;
    scanf("%llu",&x);
    if(x==1)x++;
    scanf("%llu",&y);
    if(y<x)return 0;
    if(x==2)printf("\n2");
    if(x%2==0)x+=1;
    if(y%2==0)y-=1;
    for(b=x;b<=y;b+=2)
    {
        z=b;e=0;
        for(c=2;c*c<=z;c++)
        {
            if(z%c==0)e++;
            if(e>0)z=3;
        }
        if(e==0)
        {
            printf("\n%llu",z);
            r+=1;
        }
    }
    scanf("%llu",&r);
    k++;
}
}
