#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int arr[n+9];
		stack<int> s , p;
		for(int i = 0 ; i < n ; i++){
			cin>>arr[i];
			p.push(arr[i]);
		}
		int counter = 1;
		while(!p.empty())
		{
			if(p.size() > 0 && p.top() == counter)
				p.pop() , counter++;
			else
			{
				if(!s.empty())
			}
		}
		if(flag)
			cout<<"no\n";
		else cout<<"yes\n";
	}
	return 0;
}