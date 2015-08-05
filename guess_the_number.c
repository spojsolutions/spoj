#include<stdio.h>
long long int LCM(int a,int b);
int main()
{
    while(1)
    {
        char S[21];
        scanf("%s",S);
        if(*S=='*')
        break;
        int i=0,j=0,flage=0;
        long long int mul_Y=1;
        int B[20];
        while(S[i]!='\0')
        {
            if(S[i]=='Y')
            {
           mul_Y=LCM(mul_Y,(i+1));
            }
            else
            {
            B[j]=i+1;
            j++;
            }
            i++;
        }
       for(i=0;i<j;i++)
       if(mul_Y%B[i]==0)
        flage=1;
        if(flage==0)
        printf("%lld\n",mul_Y);
        else
        printf("%d\n",-1);
    }
    return 0;
}
long long int LCM(int a,int b)
{
    long long int temp;

    if(a>b){
        if(b==0)
    return a;
    else{
    temp=a;
    while(temp%b!=0)
    temp+=a;
    return temp;}
    }
    else{{
        if(a==0)
    return b;}
    temp=b;
    while(temp%a!=0)
    temp+=b;
    return temp;
    }
}


