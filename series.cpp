#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define PB push_back
int digit(ULL num)
{
	int count = 0;
	while(num)
	{
		count++;
		num/=10;
	}
	return count;
}
vector<ULL> calc()
{
	vector<ULL> v;
	for(int i=1;i<=9;i++)
		v.PB(i);
	ULL num=0,dig=2,hold=4;
	for(int i=0;i<17;i++)
	{
		int j = hold;
		int flag = 1;
		while(j<v.size() && digit(v[j]*dig)<=(dig+1))
		{
			if(digit(v[j]*dig)==dig){
				v.PB(v[j]*dig);
			}
			if(digit(v[j]*(dig+1)) == (dig+1) && flag == 1){
				hold = j;
				flag = 0;
			}
			j++;
		}
		dig++;
	}
	return v;
}
int main()
{
	vector<ULL> v;
	v = calc();
	for(int i=0;i<v.size();i++)
		cout<<i<<" - "<<v[i]<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		LL l,r;
		cin>>l>>r;
		int lpos,rpos;
		lpos = (lower_bound(v.begin(),v.end(),l) - v.begin());
		rpos = (lower_bound(v.begin(),v.end(),r) - v.begin());
		cout<<lpos<<"  "<<rpos<<endl;
	}
	return 0;
}
