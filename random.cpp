#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
long long irand(long long min, long long max) {
    return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}
int main()
{
	cout<<100000<<" "<<100000<<endl;
	for(int i = 0 ; i< 100000 ; i++)
		cout<<irand(1 , 1000000000)<<" ";
	cout<<endl;
	for(int i = 0 ; i < 100000 ; i++){
		int type = irand(1 , 4);
		if(type == 4){
			cout<<type<<" "<<irand(1 , 1000)<<" "<<irand(1001 , 100000)<<endl;
		} else{
			cout<<type<<" "<<irand(1 , 10000)<<" "<<irand(10001 , 100000)<<" "<<irand(1 , 1000000000)<<endl;
		}
	}
	return 0;
}