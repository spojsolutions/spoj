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
long long irand(long long min, long long max) {
    return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}
int main()
{
	fstream file("data.txt");
	int i;
	if(file.is_open())
	{
		for(i=0;i<100;i++)
			file<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<" "<<irand(0,100)<<endl;
		file.close();
	}
	else
		cout<<"can't open file\n";
	return 0;
}