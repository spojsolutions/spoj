#include<stdio.h>
void fib(int n)
{
    unsigned long long a = 0;
    unsigned long long b = 1;
    while (n-- > 1) {
        unsigned long long t = a;
        a = b;
        b += t;
        printf("%llu\n",b);
    }
}
int main()
{
    fib(100);
    return 0;
}