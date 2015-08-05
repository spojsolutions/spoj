#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       long long int num,temp,div=2;
       scanf("%d",&num);
       int i,count=0;
       char A[50];
       temp=num;
       while(temp/div!=0)
       {
           count++;
           div=div*2;
       }
       printf("%d\n",count);
       for(i=count;i>=1;i--)
       {
           long long int mask,j,k;
           j=i;
           mask=1<<j;
           k=num&mask;
           printf("%d",k);
           k==0?A[count-i]==5-48:A[count-i]==6-48;
       }
       printf("\n");
       for(i=count;i>=0;i--)
       printf("%c",A[i]);
    }
    return 0;
}
