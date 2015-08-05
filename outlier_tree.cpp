#include <bits/stdc++.h>
#define MAX 500
using namespace std;
int line;
class point
{
public:
	double att[35];
	int pos;
	double dist(point p)
	{
		double temp;
		for(int j=0;j<30;j++)
		{
			temp= (att[j] - p.att[j])*(att[j] - p.att[j]);
		}
		return sqrt(temp);
	}
	void operator =(point p)
	{
		int i;
		for(i=0;i<30;i++)
			att[i]= p.att[i];
		pos= p.pos;
	}
	bool operator==(point p)
	{
		for(int i=0;i<30;i++)
			if(att[i]!=p.att[i])
				return false;
		return true;
	}
	bool operator==(int x)
	{
		for(int i=0;i<30;i++)
			if(att[i]!=x)
				return false;
		return true;
	}
	bool operator!=(int x)
	{
		for(int i=0;i<30;i++)
			if(att[i]!=x)
				return true;
		return false;
	}
	void operator =(int x)
	{
		int i;
		for(i=0;i<30;i++)
			att[i]=x;
		pos= x;
	}
	void print()
	{
	}
}p[MAX];
int si=line;
class vectu
{
public:
	point arr[MAX];
	void er(point p)
	{
		for(int i=0;i<si;i++)
			if(p==arr[i])
			{
				for(int j=i;j<si-1;j++)
					arr[j]=arr[j+1];
				break;
			}
		si--;
	}
}vec;
class len
{
public:
	double dis;
	point pk;
};
void merge_sort(len  dista[],int low,int mid,int high)
{
	int i=low,k=low,j=mid+1;
	len temp[MAX];
	while(i<=mid && j<=high)
	{
		if(dista[i].dis < dista[j].dis)
			temp[k++] = dista[i++];
		else
		{
			temp[k++] = dista[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++] = dista[i++];
	}
	while(j<=high)
	{
		temp[k++] = dista[j++];;
	}
	for(i=low;i<=high;i++)
	{
		dista[i] = temp[i];
	}
}
void partition(len dista[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(dista,low,mid);
		partition(dista,mid+1,high);
		merge_sort(dista,low,mid,high);
	}
}
point TREE[2000];
point * find_Min_2(point pu)
{
	point *m;
	m = (point *)calloc(2,sizeof(point));
	m[0]=-1;m[1]=-1;
	len distu[MAX];
	if(si<1)
		return m;
	for(int i=0;i<si;i++)
		distu[i].dis = pu.dist(vec.arr[i]) , distu[i].pk = vec.arr[i];
	partition(distu,0,si-1);
	for(int i=0;i<2;i++)
		m[i] = distu[i].pk;
	return m;
}
void construct(point cen)
{
	for(int i=0;i<2000;i++)
		TREE[i]=-1;
	TREE[1] = cen;
	int k;
	point *m;
	m = (point *)calloc(5,sizeof(point));
	m = find_Min_2(cen);
	for(int i=0;i<2;i++){
		TREE[2+i] = m[i];
		vec.er(m[i]);
	}
	for(int i=2;si>=0;i++)
	{
		m = find_Min_2(TREE[i]);
		for(int j=0;j<2;j++)
		{
			TREE[2*i + j] = m[j];
			vec.er(m[j]);
		}
	}
}
fstream wr("op.txt");
void pr(point p)
{
	for(int i=0;i<30;i++)
		wr<<p.att[i]<<"   ";
	wr<<"\n\n\n";
}
void find_oulier()
{
	int count=0;
	for(int i=1;i<2000;i++)
		if(TREE[i]!=-1)
		{
			if(TREE[2*i]==-1 && TREE[2*i + 1]== -1){
				pr(TREE[i]);
				count++;
				}
		}
		cout<<endl<<count<<endl;
}
int main()
{
	ifstream data("data2.txt");
	point cent;
	string s;
	double x;
	int i,j,k;
	if(data.is_open())
	{
		i=0;
		while(getline(data,s))
		{
			istringstream iss(s);
			j=0;
			while(iss>>x)
			{
				p[i].att[j]=x;
				cent.att[j]+=x;
				j++;
			}
			p[i].pos=i;
			vec.arr[i] = p[i];
			i++;
		}
	}
	line = i;
	si=i;
	len dista[MAX]; 
	for(i=0;i<30;i++)
		cent.att[i]/=line;
	construct(cent);
	find_oulier();
	return 0;
}