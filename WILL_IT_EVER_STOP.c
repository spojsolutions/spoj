#include<stdio.h>
long long int gcd(long long int a, long long int b);
int main()
{
    int t=0,n;
    scanf("%d",&n);
    while(t<n)
    {
        long long int number;
        scanf("%lld",&number);
        long long int i;
        for(i=number/2;i>=0;i--)
        {
            if(gcd(i,number)==1){
            printf("%lld\n",i);
            break;
            }
        }
        t++;
    }
}
long long int gcd(long long int a, long long int b)
{
long long int temp;

while(b)
{
temp = a % b;
a = b;
b = temp;
}

return(a);
}
