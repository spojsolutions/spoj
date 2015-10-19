/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 08 August 2015 (Saturday) 22:22
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
bool check(int mat[][10] ,int c_row , int c_col, int row){
	for(int i = c_col-1; i>=0; i--)
		if(mat[c_row][i])
			return false;
	int i = c_row+1 ,j = c_col-1;
	while(i < row && j>=0){
		if(mat[i][j])
			return false;
		i++ , j--;
	}
	c_row--;
	c_col--;
	while(c_row >=0 && c_col>=0){
		if(mat[c_row][c_col])
			return false;
		c_row--;
		c_col--;
	}
	return true;
}
void nqueen(int mat[][10] ,int c_col,int row ){
	if(c_col == row){
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < row ; j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		return ;
	}
	for(int i = 0 ; i < row ; i++){
		if(check(mat , i , c_col , row)){
			// cout<<"dwn\n";
			// cout<<i<<" "<<c_col<<endl;
			mat[i][c_col] = 1;
			nqueen(mat ,c_col+1 , row);
			mat[i][c_col] = 0;
		}
	}
}

int main(){
	int mat[10][10];
	memset(mat , 0 , sizeof mat);
	nqueen(mat , 0 , 4);
	return 0;
}