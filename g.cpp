#include <bits/stdc++.h>
using namespace std;
int c_i,c_j;
void movement(string s[],char dir,int n,int m)
{
	int a,b,c,d;
	if(dir == 'U')
	{
		a = -1;
		b = -2;
		c = 0;
		d = 0;
	}
	else if(dir == 'D')
	{
		a = 1;
		b = 2;
		c = 0;
		d = 0;
	}
	else if(dir == 'L')
	{
		a = 0;
		b = 0;
		c = -1;
		d = -2;
	}
	else if(dir == 'R')
	{
		a = 0;
		b = 0;
		c = 1;
		d = 2;
	}
			if(s[c_i+a][c_j+c] == 'b')
			{
				if((c_j + d) >=0 && (c_j + d) < n && (c_i + b) < n && (c_i + b)>=0 && s[c_i+b][c_j+d] == '.')
				{
					s[c_i+b][c_j+d] = 'b';
					s[c_i+a][c_j+c] = 'w' ;
					if(s[c_i][c_j] == 'W')
						s[c_i][c_j] = '+';
					else
						s[c_i][c_j] = '.';
					c_i += a;
					c_j += c;
				}
				else if((c_j + d) >=0 && (c_j + d) < n && (c_i + b) < n && (c_i + b)>=0 && s[c_i+b][c_j+d] == '+')
				{
					s[c_i+b][c_j+d] = 'B';
					s[c_i+a][c_j+c] = 'w' ;
					if(s[c_i][c_j] == 'W')
						s[c_i][c_j] = '+';
					else
						s[c_i][c_j] = '.';
					c_i += a;
					c_j += c;
				}
			}
			else if(s[c_i+a][c_j+c] == 'B')
			{
				if((c_j + d) >=0 && (c_j + d) < n && (c_i + b) < n && (c_i + b)>=0 && s[c_i+b][c_j+d] == '.')
				{
					s[c_i+b][c_j+d] = 'b';
					s[c_i+a][c_j+c] = 'W' ;
					if(s[c_i][c_j] == 'W')
						s[c_i][c_j] = '+';
					else
						s[c_i][c_j] = '.';
					c_i += a;
					c_j += c;
				}
				else if((c_j + d) >=0 && (c_j + d) < n && (c_i + b) < n && (c_i + b)>=0 && s[c_i+b][c_j+d] == '+')
				{
					s[c_i+b][c_j+d] = 'B';
					s[c_i+a][c_j+c] = 'W' ;
					if(s[c_i][c_j] == 'W')
						s[c_i][c_j] = '+';
					else
						s[c_i][c_j] = '.';
					c_i += a;
					c_j += c;
				}
			}
			else if(s[c_i+a][c_j+c] == '.')
			{
				s[c_i+a][c_j+c] = 'w' ;
				if(s[c_i][c_j] == 'W')
					s[c_i][c_j] = '+';
				else
					s[c_i][c_j] = '.';
				c_i += a;
				c_j += c;
			}
			else if(s[c_i+a][c_j+c] == '+')
			{
					s[c_i+a][c_j+c] = 'W' ;
					if(s[c_i][c_j] == 'W')
						s[c_i][c_j] = '+';
					else
						s[c_i][c_j] = '.';
					c_i += a;
					c_j += c;
			}
}
int main()
{
	int n,m,count=1,cp;
	while(1)
	{
		cin>>n>>m;
		cp=0;
		c_i=0;
		c_j=0;
		if(n==0 && m==0)
			return 0;
		string s[n+9];
		for(int i=0;i<n;i++)
			cin>>s[i];
		string input;
		cin>>input;
		int flag = 1;
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++){
				if(s[i][j] == 'w' || s[i][j] == 'W'){
					c_j = j;
					c_i = i;
				}
				if(s[i][j] == '+' || s[i][j] == 'W' ||s[i][j] == 'B'){
					v.push_back(make_pair(i,j));
					cp++;
				}
			}
		}
		for(int i=0;i<input.size();i++){
			movement(s,char(input[i]),n,m);
			int fl = 0;
			if(cp!=0)
				for(int i=0;i<v.size();i++)
					if(s[v[i].first][v[i].second] != 'B'){
						fl = 1;
						break;
					}
			if(fl == 0 && cp!=0){
				flag = 0;
				break;
			}
		}
		if(cp==0)
		{
			cout<<"Game "<<count<<": "<<"incomplete"<<endl;
			for(int i=0;i<n;i++){
				for(int j = 0;j<m;j++)
					cout<<s[i][j];
				cout<<endl;
			}
			continue;
		}
		if(flag == 1)
		{
			cout<<"Game "<<count<<": "<<"incomplete"<<endl;
			for(int i=0;i<n;i++){
				for(int j = 0;j<m;j++)
					cout<<s[i][j];
				cout<<endl;
			}
		}
		else
		{
			cout<<"Game "<<count<<": "<<"complete"<<endl;
			for(int i=0;i<n;i++){
				for(int j = 0;j<m;j++)
					cout<<s[i][j];
				cout<<endl;
			}
		}
		count++;
	}
}