#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
#define max 1000001

int main()
{


    int t, a, b;
    scanint(t);
    while(t--)
    {
        scanint(a);
        scanint(b);
        int A = sqrt(a);
        int B = sqrt(b);

        if(A==B)
        {
            printf("0\n");
            continue;
        }

        int l,r,i;
        l = r = (A+1)*(A+1) - A*A;
        for(i = A + 1; i < B ; ++i )
        {
            int temp = (i + 1)*(i + 1) - i*i;
            l = l & temp;
            r = r ^ temp;
        }

        printf("%d\n", l & r);
    }
    return 0;
}
