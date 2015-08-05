#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define gc getchar_unlocked
inline void scan(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	int t,p,x,temp,flag;
	scan(t);
	while (t--)
	{
		scan(p);
		scan(x);
		flag=1;
		char array[p+9];
		for (int i=x; i<10; i++)
		{
			//int *array=(int *)calloc (p,sizeof(int));
			array[p-1]=i+48;
			temp=0;
			for (int j=p-2; j>=0; j--)
			{
				array[j]=(((array[j+1]-48)*x)+temp)%10 +48 ;
				temp=(((array[j+1]-48)*x)+temp)/10;
			}
			array[p]=0;
			if (array[0]==49&& x+temp==i )
			{
				flag=0;
				printf("%s\n",array);
				break;
			}
		}
		if (flag)
			printf("Impossible\n");
	}
	return 0;
}
