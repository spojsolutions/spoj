#include<stdio.h>
#include<math.h>
long unsigned int ZERO(long unsigned int num);
int main()
{
    int t,n=0;
    scanf("%d",&t);
    while(n<t)
    {
        long unsigned int no_of_zero;
        long unsigned int num;
        scanf("%ld",&num);
        no_of_zero=ZERO(num);
        printf("%ld\n",no_of_zero);
        n++;
    }
    return 0;
}
long unsigned int ZERO(long unsigned int num)
{
    long unsigned int number_of_zeros=0;
    int i=1;
    while(num/pow(5,i)!=0)
    {
        number_of_zeros=number_of_zeros+num/pow(5,i);
        i++;
    }
    return number_of_zeros;
}
