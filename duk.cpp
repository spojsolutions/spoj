#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	string s,key,info;
	//char key[10],info[1000];
	while(!cin.eof())
	{
		cin>>key>>info;
		int array[key.length()];
		for (int i=0; i<key.length(); i++)
			array[i]=key[i]-48;
		int temp=(info.length()/key.length())+20;
		string mat[temp][key.length()];
		for (int i=0; i<temp; i++)
			for (int j=0; j<key.length(); j++)
				mat[i][j]="1";
		int j=0,k=0,i=0,count=0;
		for (int i=0; i<info.length(); )
		{
			if (count%2==0)
			{
				s=info[i++];
				s+=info[i++];
			}
			else
				s=info[i++];
			mat[j][k]=s;
			k++;
			count++;
			if (k==key.length())
			{
				j++;
				k=0;
			}
		}
		i=1;
		int array1[key.length()];
		for (i=0; i<key.length(); i++)
			array1[array[i]-1]=i;
		for (i=0; i<key.length(); i++)
		{
			j=0;
			while (mat[j][array1[i]]!="1")
			{	cout<<mat[j][array1[i]];
				j++;
			}
		}
		cout<<endl;
	}
	return 0;
}