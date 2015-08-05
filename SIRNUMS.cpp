#include <bits/stdc++.h>
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
	int t;
	scan(t);
	while(t--){
	int k,x;
	scan(k);
	scan(x);
	char a[1000009];
	int temp,carry,temp1;
	int flag=0;
	for(int i=x;i<=9;i++)
	{
		a[k-1]=i+48;
		carry=0;
		for(int j=k-2;j>=0;j--)
		{
			a[j]=((a[j+1]-48)*x + carry)%10 + 48;
			carry = ((a[j+1]-48)*x + carry)/10;
		}
		a[k]=0;
		temp=a[0]-48;
		temp1= (temp*x + carry)%10;
		carry=(temp*x + carry)/10;
		if(temp1 == i && carry==0){
			ECRIRE(s)
			printf("\n");
			flag=1;
			break;
		}
	}
	if(!flag)
		printf("Impossible\n");
	}
	return 0;
}

