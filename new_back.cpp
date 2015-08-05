#include<iostream>

using namespace std;

void Tour(int arr[],int size,int reSum)
{
	int *stack=new int[size];
	int sp=-1;
	int sum=0;
	int arrp;
	
	for(int i=0;i<size;i++)
	{
		sp=-1;
		stack[++sp]=i;
		sum+=arr[stack[sp]];
		arrp=i+1;
		while(sp!=-1)
		{
			if(sum==reSum)
			{
				for(int j=0;j<=sp;j++)
				{
					cout<<" "<<arr[stack[j]];
				}
				cout<<endl;
				arrp=stack[sp--];
				sum+=arr[arrp];
				arrp++;
			}
			else if(sum>reSum)
			{
				sum+=arr[stack[sp]];
				arrp=stack[sp--];
				arrp++;
			}
			else if(sum<reSum)
			{
				if(arrp<size)
				{
					sum+=arr[arrp];
					stack[++sp]=arrp;
					arrp++;
				}
				else
				{
					arrp=stack[sp--];
					sum+=arr[arrp];
					arrp++;
				}
			}
		}
	}
}

int main()
{
	int arr[]={100,-100,200,-200,-50,50};
	for(int i=0;i<6;i++)
		cin>>arr[i];
	int size=6;
	Tour(arr,size,0);
	return 0;
}