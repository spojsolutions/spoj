#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {

    int number;
    scanf("%d",&number);
    int MEN[number],WOMEN[number],sum=0;
    int i;
    for(i=0;i<number;i++)
    scanf("%d",&MEN[i]);
    for(i=0;i<number;i++)
    {
    scanf("%d",&WOMEN[i]);
    sum=sum + MEN[i]*WOMEN[i];
    }
    printf("%d\n",sum);
    }
return 0;
}



