#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,count = 0,flag = 0,flag2 = 0;
		cin>>n;
		int arr[n+1],arr1[n+1];
		memset(arr,0,sizeof(arr));
		memset(arr1,0,sizeof(arr1));
		for (int i=1; i<=n; i++)
		{
			int temp;
			cin>>temp;
			if (temp>=n)
				flag = 1;
			count+=temp;
			arr1[i] = temp;
		}
		if (count!=n)
			flag = 1;
		if (flag == 1)
		{
			cout<<-1<<endl;
			continue;
		}
		for (int i = 1; i<=n; i++)
		{
			int temp1 = arr1[i];
			for (int j=0; j<temp1; j++)
			{
				for (int k=1; k<=n; k++)
				{
					if (arr[k]==0)
					{
						//cout<<i<<" "<<j<<" "<<k<<endl;
						arr[k] = i;
						break;
					}
				}
			}
		}
		for (int i = 1; i<=n; i++)
		{
			if (arr[i] == i)
			{
				for (int j=1; j<=n; j++)
				{
					if (i!=j && arr[j]!=i){
						swap(arr[i],arr[j]);
						break;
					}

				}
			}
		}
		for (int i=1; i<=n; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}
	return 0;
}