#include <stdio.h>

int memo[10000]; // adjust to however big you need, but the result must fit in an int
                 // and keep in mind that fibonacci values grow rapidly :)

int fibonacci(int n) {
  if (memo[n] != -1)
    return memo[n];

  if (n==1 || n==2)
    return 1;
  else
    return memo[n] = fibonacci(n-1) +fibonacci(n-2);
}
int main() {int i;
  for(i = 0; i < 10000; ++i)
    memo[i] = -1;
  printf("%d",fibonacci(100000000000000000));
}
