#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char S[50002]={"\0"};
        scanf("%s",S);
        int count=0,i=0,sum=0,digit_sum=0,num;
        while(S[i]!='\0')
        {
            count++;
            digit_sum=digit_sum+S[i]-48;
            sum=sum*10;
            sum=sum+S[i]-48;
            sum=sum%7;
            i++;
        }
        num=(S[count-2]-48)*10+(S[count-1]-48);
            if(sum==0&&num%4==0&&digit_sum%9==0)
            printf("Yes ");
            else
            printf("No ");
            if(sum==0&&num%25==0&&digit_sum%3==0)
            printf("Yes");
            else
            printf("No");
            printf("\n");
    }
    return 0;
}
