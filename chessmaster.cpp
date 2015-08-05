#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
int main()
{
	string s[10];
	for(int i=0;i<8;i++)
		cin>>s[i];
	int check[10][10];
	for(int i=0;i<8;i++)
	{
		for(int j = 0;j<8;j++)
		{
			check[i][j] = 0;
		}
	}
	pair<int,int> pos;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j] == 'Q')
				check[i][j] = 2;
			else if(s[i][j] == 'R')
				check[i][j] = 3;
			else if(s[i][j] == 'B')
				check[i][j] = 4;
			else if(s[i][j] == 'S')
				check[i][j] = 1;
			else
				pos = MP(i,j);
		}
	}
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			int p,q;
			if(check[i][j] == 2)
			{
				p = i;
				q = j;
				while(q<8)
					check[i][q++] = 10;
				q = j;
				while(q>=0)
					check[i][q--] = 10;
				while(p<8)
					check[p++][j] = 10;
				p = i;
				while(p>=0)
					check[p--][j] = 10;
				p =i,q=j;
				while(p<8 && q<8)
					check[p++][q++] = 10;
				p = i,q=j;
				while(p>=0 && q>=0)
					check[p--][q--] = 10;
				p = i,q=j;
				while(p>=0 && q<8)
					check[p--][q++] = 10;
				p = i,q=j;
				while(p<8 && q>=0)
					check[p++][q--] = 10;
			}
			else if(check[i][j]==3)
			{
				p=i,q=j;
				while(p<8 && q<8)
					check[p++][q++] = 10;
				p = i,q=j;
				while(p>=0 && q>=0)
					check[p--][q--] = 10;
				p = i,q=j;
				while(p>=0 && q<8)
					check[p--][q++] = 10;
				p = i,q=j;
				while(p<8 && q>=0)
					check[p++][q--] = 10;
			}
			else if(check[i][j] == 4)
			{
				p =i,q=j;
				while(q<8)
					check[i][q++] = 10;
				q = j;
				while(q>=0)
					check[i][q--] = 10;
				while(p<8)
					check[p++][j] = 10;
				p = i;
				while(p>=0)
					check[p--][j] = 10;
			}
			else if(check[i][j] == 1)
			{
				if(i!=7){
					check[i+1][j] = 10;
				}
				if(i!=7 && j!=7)
					check[i+1][j+1]  = 10;

				if(i!=0 && j!=7)
					check[i-1][j+1] =10;

				if(i!=0 && j!=0)
					check[i-1][j-1] = 10;
				if(i!=7 && j!=0)
					check[i+1][j-1] =10;

				if(j!=7)
					check[j][j+1] = 10;
				if(i!=0)
					check[i-1][j] = 10;
				if(j!=0)
					check[i][j-1] = 10;
			}
		}
	}
	int i,j;
	i = pos.first;
	j = pos.second;
	vector<pair<int,int> > v;
	v.push_back(MP(i+1,j));
	v.push_back(MP(i-1,j));
	v.push_back(MP(i,j+1));
	v.push_back(MP(i,j-1));
	v.push_back(MP(i-1,j-1));
	v.push_back(MP(i-1,j+1));
	v.push_back(MP(i+1,j-1));
	v.push_back(MP(i+1,j+1));
	int flag = 0;
	for(i=0;i<8;i++)
	{
		if((v[i].first>=0 && v[i].first<8) && (v[i].second>=0 && v[i].second<8))
		{
			if(check[v[i].first][v[i].second]!=10)
				flag = 1;
		}
	}
	if(flag)
		cout<<"NOT YET!\n";
	else
		cout<<"CHECKMATE!\n";
	return 0;
}