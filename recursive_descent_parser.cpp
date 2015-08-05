#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;
int i = 0;
string s;
void advance(){i++;}
bool F();
bool E();
bool T();
bool E_();
bool T_();
bool F();

bool F(){
	int isave = i;
	if(s[i]=='('){
		advance();
		if(E()){
			if(s[i]==')'){
				advance();
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	i = isave;
	if(isalpha(s[i])){
		advance();
		return true;
	}
}
bool T_(){
	int isave = i;
	if(s[i] == '*'){
		advance();
		if(F()){
			if(T_())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	i = isave;
	return true;
}

bool T(){
	if(F()){
		if(T_())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool E_(){
	int isave = i;
	if(s[i] == '+'){
		advance();
		if(T()){
			if(E_())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	i = isave;
	return true;
}

bool E(){
	if(T()){
		if(E_())
			return true;
		else
			return false;
	}
	else 
		return false;
}

int main(){
	cout<<"Enter String\n";
	cin>>s;
	if(E())
		cout<<"Valid\n";
	else
		cout<<"Invalid\n";
}
