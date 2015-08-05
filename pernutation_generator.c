#include<stdio.h>
int main()
{
    int j=1,k=1,l=1,m=1,n=1;
    for(j=1;j<=5;j++)
    {
        while(k!=j)
        {
            while(l!=k)
            {
                while(m!=l)
                {
                    while(n!=m)
                    {
                    printf("%d%d%d%d%d\n",j,k,l,m,n);
                    n++;
                    }
                    m++;
                }

                l++;
            }
            k++;
        }
    }

    return 0;
}
