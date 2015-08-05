#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int V;
class data
{
public:
	double x,y,weight;
};
void merge_sort(data d[],int low,int mid,int high)
{
	int i=low,k=low,j=mid+1;
	data temp[MAX];
	while(i<=mid && j<=high)
	{
		if(d[i].weight < d[j].weight)
			temp[k++]=d[i++];
		else
			temp[k++]=d[j++];
	}
	while(i<=mid)
		temp[k++]=d[i++];
	while(j<=high)
		temp[k++]=d[j++];
	for(i=low;i<=high;i++)
		d[i]=temp[i];
}
void partition(data d[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(high+low)/2;
		partition(d,low,mid);
		partition(d,mid+1,high);
		merge_sort(d,low,mid,high);
	}
}
int minKey(double key[], bool mstSet[])
{
   int min_index;
 	double min = DBL_MAX;
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
int printMST(int parent[], int n, double graph[MAX][MAX])
{
	data d[MAX];
   	for (int i = 1; i < V; i++)
      	d[i].x= parent[i], d[i].y= i, d[i].weight = graph[i][parent[i]];
    partition(d,0,V-1);
    ofstream file("output1.txt");
    if(file.is_open()){
    	file<<"    Edge"<<"         weight"<<endl;
    	for(int i=1;i<V;i++)
    		file<<d[i].x<<"  -   "<<d[i].y<<"     "<<d[i].weight<<endl;
    }
    file.close();
}
void primMST(double graph[MAX][MAX])
{
     int parent[MAX];
     double key[MAX];   
     bool mstSet[MAX];  
     for (int i = 0; i < V; i++)
        key[i] = DBL_MAX, mstSet[i] = false;
     key[0] = 0; 
     parent[0] = -1;
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST(parent, V, graph);
}
int main()
{
	ifstream file("data2.txt");
	string s;
	int i=0,j=0,k,count;
	double temp,arr[MAX][MAX]={0},graph[MAX][MAX]={0};
	int min = INT_MAX,ind;
	if(file.is_open())
	{
		i=0;
		while(getline(file,s))
		{
			istringstream iss(s);
			j=0;
			while(iss>>temp)
			{
				arr[i][j++] = temp;
			}
			i++;
		}
	}
	file.close();
	V=i;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			temp=0;
			if(i != j)
			{
				for(k=0 ;k<30;k++)
					temp+=(arr[i][k] - arr[j][k])*(arr[i][k] - arr[j][k]);
				graph[i][j] = sqrt(temp);
			}
		}
	}
	primMST(graph);
	return 0;
}