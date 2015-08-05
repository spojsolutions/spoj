#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
class vertex
{
public:
	int n1,n2;
};
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
vertex temp[200009];
void mergesort(vertex v[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
	while(i<=mid && j<=high)
	{
		if(v[i].n1<v[j].n1)
			temp[k++]=v[i++];
		else
			temp[k++]=v[j++];
	}
	while(i<=mid)
		temp[k++]=v[i++];
	while(j<=high)
		temp[k++]=v[j++];
	for(i=low;i<=high;i++)
		v[i]=temp[i];
}
void partition(vertex v[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low + high)/2;
		partition(v,low,mid);
		partition(v,mid+1,high);
		mergesort(v,low,mid,high);
	}
}
int main()
{
	int n,m,t=0;
	while(scanf("%d%d",&n,&m)!=EOF){t++;
	int i,temp,temp1;
	int *deg=(int *)calloc(n+9,sizeof(int));
	//int *in=(int *)calloc(n+9,sizeof(int));
	//int *out=(int *)calloc(n+9,sizeof(int));
	vertex *v=(vertex *)calloc(m+9,sizeof(vertex));
	for(i=1;i<=m;i++)
	{
		scanint(temp);
		scanint(temp1);
		v[i].n1=temp;
		v[i].n2=temp1;
		deg[temp]++;
		deg[temp1]++;
	}
	partition(v,1,n);
	int count=0,k=0;
	int pos[n+1];
	for(i=1;i<=n;i++)
	{
		if(deg[i]%2!=0 && deg[i]>1)
		{
			count++;
			pos[k++]=i;
		}
		if(deg[i]<=1)
		{
			count=0;
			break;
		}
	}
	int check[4]={1,1,1,1},j,l,position[10];
	k=-1;
	if(count==4)
	{
		for(i=0;i<4;i++)
		{
			temp=pos[i];
			if(check[i]!=0)
			{
				check[i]=0;
				for(j=1;j<=m;j++)
				{
					int flag=0;
					if(v[j].n1==temp)
					{
						for(l=0;l<4;l++)
						{
							if(l!=i)
							{
								if(pos[l]==v[j].n2 && check[l]!=0)
								{
									position[++k]=j;
									check[l]=0;
									flag=1;
									break;
								}
							}
						}
					}
					if(flag)
						break;
				}
			}
		}
		if(k==1){
			printf("Case %d: YES\n",t);
			printf("%d %d\n",position[0],position[1]);

		}
		else
			printf("Case %d: NO\n",t);
	}
	else
		printf("Case %d: NO\n",t);
}
}