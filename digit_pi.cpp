//spigot algo
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define NDIGIT 15000
#define LEN (NDIGIT/4+1)*14
long a[LEN];
long b,c=LEN,d,e=0,f=10000,g,h=0;
int main()
{
	int flag=1;
	for( ; (b=c-=14)>0 ; )
	{
		for(;--b>0;)
		{
			d*=b;
			if(h==0)
				d+=2000 * f;
			else
				d+=a[b] * f;
			g=b+b-1;
			a[b]=d%g;
			d/=g;
		}
		if(flag==1){
			h=printf("3.141");
			flag=0;
		}
		else
			h=printf("%04ld",e+d/f);
		d=e=d%f;
	}
	return 0;
}