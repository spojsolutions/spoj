#include<stdio.h>
#include<stdint.h>
#include<math.h>
long double fact (int num);
int main()
{
    long int n=0;
    long double pi,temp=0;
    for(n=0;n<100;n++)
    temp=temp+((fact(4*n))*(1103+26390*n))/((pow(fact(n),4))*(pow(396,4*n)));
    temp=temp*(sqrt(8))/9801;
    pi=1/temp;
    printf("%lf",pi);
    return 0;
}
long double fact (int num)
{
    long double temp=1;
    int i;
    for(i=0;i<num;i++)
    temp=temp*i;
    return temp;
}



