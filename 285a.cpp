#include <bits/stdc++.h>
using namespace std;
int main(){
	int a , b , c , d;
	cin>>a>>b>>c>>d;
	int points_a , points_b;
	points_a = max((3*a)/10 , (a*250 - a*c)/250);
	points_b = max((3*b)/10 , (b*250 - b*d)/250);
	if(points_b > points_a)
		cout<<"Vasya\n";
	else if(points_a > points_b)
		cout<<"Misha\n";
	else
		cout<<"Tie\n";
	return 0;
}