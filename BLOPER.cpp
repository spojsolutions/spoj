#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s,i;
	cin>>n>>s;
	bool flag=false;
	bool check[510]={false};
	if(s<0){
		flag = true;
		s=-1*s;}
	int total = n*(n+1)/2;
	int half=total-s;
	if(half & 1 || total <s)
		printf("Impossible\n");
	else
	{

		half>>=1;
		if(flag)
			half-=1;
		for(i=n;i>1;i--)
		{
			if(half-i >1){
				half-=i;
				check[i] = true;
			}
			else if(half - i ==0)
			{
				half-=i;
				check[i] = true;
				break;
			}
		}
		if(half)
			printf("Impossible\n");
		else
		{
			printf("1");
			if(flag)
				for(i=2;i<=n;i++)
					check[i]?cout<<"+"<<i:cout<<"-"<<i;
			else
				for(i=2;i<=n;i++)
					check[i]?cout<<"-"<<i:cout<<"+"<<i;
			cout<<endl;
		}
	}
	return 0;
}