#include<stdio.h>
#include<string.h>
int main()
{
    int t=0,n;
    scanf("%d",&n);
    while(t<n)
    {
        long long int num;
        scanf("%lld",&num);
        long long int quotient=num;
        int i=0,j;
        char A[100]={"\0"};
        while(quotient!=0)
        {
            j=quotient%5;
            if(j==0)
            A[i]='m';
            else if(j==1)
            A[i]='a';
            else if(j==2)
            A[i]='n';
            else if(j==3)
            A[i]='k';
            else if(j==4)
            A[i]='u';
            i++;
            quotient=quotient/5;
        }
        char *temp;
        temp=(char *)malloc(100*sizeof(char));
        temp=strrev(A);
        printf("%s\n",temp);
        t++;
    }
    return 0;
}
