#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	double a[20]={0},sq[20]={0},b[20]={0},result;
	string s;
	int i,j,count=0;
	double temp;
	ifstream data("data.txt");
	if(data.is_open())
	{
		while(getline(data,s))
		{
			istringstream iss(s);
			i=0;
			int upto =0;
			while(iss>>temp && upto <=1)
			{
				upto++;
				a[i]=temp;
				b[i]+=a[i];
				sq[i]+=a[i]*a[i];
				i++;
			}
			count++;
		}
	}
	data.close();
	ofstream res("output.txt");
	if(res.is_open()){
		for(j=0;j<i;j++)
		{
			result = sq[j]/count - (b[j]/count)*(b[j]/count);
			res<<"Attribute "<<j+1<<" Variance = "<<result<<endl;
			res<<"Attribute "<<j+1<<" SD = "<<sqrt(result);
			res<<endl<<endl;
		}
	}
	res.close();
	//cout<<endl;
	return 0;
}