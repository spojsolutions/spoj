#include <stdio.h>
int main()
{
	long a;
	scanf("%ld",&a);
	if(a%10==0)
		printf("2\n");
	else {
		printf("1\n");
		printf("%ld\n",a%10);}
	return 0;
}