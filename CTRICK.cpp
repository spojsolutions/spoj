#include <bits/stdc++.h>
using namespace std;
#define MAX 6
int tree[100009];
void update(int pos,int val)
{
	while(pos <= MAX)
	{
		tree[pos]+=val;
		//cout<<pos<<" ";
		pos +=(pos & -pos);
		//cout<<"h\n";
	}
}
int read(int pos)
{
	int res=0,count = 0;;
	while(pos)
	{
		res += tree[pos];
		pos -= (pos & -pos);
	}
	return res;
}
int main()
{
	int pos = 0,p = 0;
	int count = 2,total = 6;
	for(int i=1;i<=6;i++){
		update(i,1);
	}
	for(int i=1;i<=6;i++)
		cout<<read(i)<<"  ";
	cout<<endl;
	return 0;
}