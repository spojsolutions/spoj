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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p;
		scanf("%d%d",&n,&p);
		string s;
		int temp,res=1,total=0;
		char c;
		for(int i=0;i<n;i++){
			temp=i;
			res=1;
			while(temp)
			{
				res*=(temp%p)+1;
				temp/=p;
			}
			//cout<<(i+1-res)<<endl;
			total+=(i+1-res);
		}
		while(n)
		{
			c=(n%p)+48;
			s=c+s;
			n/=p;
		}
		cout<<s<<endl;
		cout<<total<<endl;
	}
	return 0;
}