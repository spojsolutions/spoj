#include <bits/stdc++.h>
using namespace std;
struct tup{
	int first , second , third;
	tup(){}
	tup(int a , int b , int c){
		first = a , second = b , third = c;
	}
	bool operator > (tup t){
		if(first > t.first && second > t.second && third > t.third)
			return true;
		else
			return false;
	}
	tup operator - (tup t){
		tup temp;
		temp.first = first - t.first;
		temp.second = second - t.second;
		temp.third = third - t.third;
		return temp;
	}
	bool operator==(tup t){
		if(first == t.first && second == t.second && third == t.third)
			return true;
		else 
			return false;
	}
	bool operator!=(tup t){
		if(first == t.first && second == t.second && third == t.third)
			return false;
		else 
			return true;
	}
};
bool subsetsum(tup t[] , int n , tup sum)
{
	if(sum == tup(0 ,0 ,0))
		return 1;
	if(n == 0 && sum != tup(0 , 0 , 0))
		return 0;
	if(t[n-1] > sum)
		return subsetsum(t , n -1 , sum);
	return subsetsum(t , n - 1 , sum) || subsetsum(t , n - 1 , sum - t[n-1]);
}
int main()
{
	int t;
	cin>>t;
	for(int test = 1; test <= t; test ++ ){
		tup sum;
		cin>>sum.first>>sum.second>>sum.third;
		int n;
		cin>>n;
		tup t[n+9];
		for(int i = 0 ; i < n ; i++)
			cin>>t[i].first>>t[i].second>>t[i].third;
		if(subsetsum(t , n ,sum))
			cout<<"Case #"<<test<<": yes\n";
		else
			cout<<"Case #"<<test<<": no\n";
	}
	return 0;
}