#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int num,tower,harm,i,flage=0;
		cin>>num>>tower>>harm;
		int health[num];
		for(i=0;i<num;i++)
			cin>>health[i];
		sort(health,health+num);
		for(i=num-1;i>=num-tower;i--)
		{
			if(health[i]-harm<=0)
			{
				flage=1;
				break;
			}
		}
		if(flage==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}