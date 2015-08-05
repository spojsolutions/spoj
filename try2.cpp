#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include<stdio.h>
using namespace std;
int A[1000000]={0};
#define gc getchar_unlocked
inline void scanint(long &x)
{
    register long c = gc();
    x = 0;
    long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void factor()
{
  int i,j,k;
  for(i=1;i<=1000;i++)
  {
    for(j=i+1;j<=1000;j++)
    {
      for(k=1;k*(i*i+j*j)<=1000000;k++)
        A[k*(i*i+j*j)]=-1;
    }
  }
}
int main()
{  long t;
   scanint(t);
   factor();
   while(t--)
   {
      long num;
      scanint(num);
      if(A[num]==-1)
        printf("YES\n");
      else
        printf("NO\n");
  }
 return 0;
}
