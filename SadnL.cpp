#include <bits/stdc++.h>
using namespace std;
void stoi(string s , int &a , int &b)
{
	a =0 , b = 0;
	int i = 0;
	while(s[i]!= ','){
		a = a*10 + s[i] - 48 ; i++;
	}
	i++;
	while(i < s.size())
	{
		b = b*10 + s[i] - 48;
		i++;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string si;
		cin>>si;
		int  l= 0  ,s = 0;
		stoi(si , l , s);
		int arr[109][109];
		for(int i = 0 ; i < 102 ; i++)
			for(int j = 0 ; j < 102 ; j++)
				arr[i][j] = 999999;
		int a , b;
		for(int i = 0 ; i < l ; i++)
		{
			cin>>si;
			stoi(si , a, b);
			arr[a][b] = 1;
		}
		for(int i = 0 ; i < s ; i++)
		{
			cin>>si;
			stoi(si , a, b);
			arr[a][b] = 1;
		}
		for(int i = 1 ; i<=100 ; i++)
		{
			arr[i][i] = 0;
			for(int j = 1 ; j<=6 ; j++)
				arr[i][i+j] = 1;
		}
		for(int k = 1 ; k <=100 ; k++)
		{
			for(int i = 1 ; i <=100 ; i++)
			{
				for(int j = 1 ; j <=100 ; j++)
					arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
			}
		}
		cout<<arr[1][100]<<endl;
	}
	return 0;
}