#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char c;
	int temp;
	int arr[10][109];
	memset(arr,0,sizeof(arr[0][0])*10*109);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c>>temp;
		if(c=='A')
			arr[0][temp]++,arr[0][101]++;
		else if(c == 'B')
			arr[1][temp]++,arr[1][101]++;
		else if(c == 'C')
			arr[2][temp]++,arr[2][101]++;
		else if(c == 'D')
			arr[3][temp]++,arr[3][101]++;
		else if(c == 'E')
			arr[4][temp]++,arr[4][101]++;
	}
	for(int i=0;i<5;i++)
	{
		int avg = (arr[i][101]*10)/100;
		int flag = 1;
		for(int j=0;j<=100;j++)
		{
			if(arr[i][j] > avg){
				flag = 0;
				cout<<j<<" ";
			}
		}
		if(flag)
			cout<<"Nothing Unusual";
		cout<<endl;
	}
	return 0;
}