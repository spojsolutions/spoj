#include<stdio.h>
int main()
{
    char PI[17]={"\0"};
    PI[0]='3';
    PI[1]='.';
    long int i=0;
    int temp,a;
    temp=144029661%45846065;
    for(i=0;i<14;i++)
    {

        PI[2+i]=((temp*10)/45846065)+48;
        temp=(temp*10)%45846065;
    }
    printf("%s",PI);
    return 0;
}
