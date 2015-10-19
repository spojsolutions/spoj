/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 10 August 2015 (Monday) 01:05
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
bool check(vector<vector<int> >v , int row , int col , int num){
	for(int i = 0 ; i < 9 ; i++)
		if(v[row][i] == num || v[i][col] == num)
			return false;
	row /=3 , col/=3;
	for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < 3 ; j++)
			if(v[row*3 + i][col*3 + j] == num)
				return false;
	return true;
}
void solve(std::vector<std::vector<int> > v , int count){
	if(count == 81){
		
	}
}
int main(){
	
	
	
	return 0;
}