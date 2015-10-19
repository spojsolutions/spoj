/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 18 August 2015 (Tuesday) 23:55
===================================================*/
#include <bits/stdc++.h>
#include <boost>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int cnt = 0 ;
bool valid(string &s){
    if(s.size() <= 0)
        return false;
    if(s[0] == '0')
        return false;
    int val = stoi(s);
    if(val >= 1 && val <= 26)
        return true;
    return false;
}
bool cou(string &s , int pos){
	//total ++;
    if(s.size() > 0&& s[0] == '0')
        return false;
    if(pos == s.size())
        return true;
    string x , y;
    x = s.substr(pos , 1);
    if(s.size() - pos >= 2)
        y = s.substr(pos , 2);
    if(valid(x) && cou(s , pos+1 , chk))
        cnt++;
    if(valid(y) && cou(s , pos+2 , chk))
        cnt++;
    return false;
}
int main(){
	while(1){
		cnt = 0;
		string s;
		cin>>s;
		if(s[0] == '0')
			return 0;
		int chk[s.size() + 9];
		for(int i = 0 ; i < s.size() ; i++)
			chk[i] = -1;
		cou(s , 0 , chk);
		//cout<<total<<endl;
		cout<<cnt<<endl;
	}
	return 0;
}