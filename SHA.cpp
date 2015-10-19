//SHA1 c++ Programmes for lab
/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 15 October 2015 (Thursday) 00:01
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
static char hex_table[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
class str{
public:
	string s;
	str(){s = "";}
	str(string a){s = a;}
	str operator+(str a){
		string t = a.s , t1 = s , res = "";
		reverse(t.begin() , t.end());
		reverse(t1.begin() , t1.end());
		int i = 0 , j = 0 , c = 0;
		while(i < t.size() && j < t1.size()){
			int x = t[i] + t1[j] - 96 + c;
			char cc = x%2 + 48;
			res = cc+res;
			c = x/2;
			i++ , j++;
		}
		while(i < t.size()){
			int x = t[i] -48  + c;
			char cc = x%2 + 48;
			res = cc+res;
			c = x/2;
			i++;
		}
		while(j < t1.size()){
			int x = t1[i] -48  + c;
			char cc = x%2 + 48;
			res = cc+res;
			c = x/2;
			j++;
		}
		if(c){
			res = '1' + res;
		}
		return str(res);
	}
	str operator^(str a){
		string res = "";
		for(int i = 0 ; i < 32 ; i++){
			char c = ((s[i]-48)^(a.s[i]-48)) + 48;
			res = res + c;
		}
		return str(res);
	}
	str operator|(str a){
		string res = "";
		for(int i = 0 ; i < 32 ; i++){
			char c = ((s[i]-48)|(a.s[i]-48)) + 48;
			res = res + c;
		}
		return str(res);
	}
	str operator&(str a){
		string res = "";
		for(int i = 0 ; i < 32 ; i++){
			char c = ((s[i]-48)&(a.s[i]-48)) + 48;
			res = res + c;
		}
		return str(res);
	}
	str operator!(){
		string res = "";
		for(int i = 0 ; i < 32 ; i++){
			res = res + (s[i] == '0'? '1' : '0');
		}
		return str(res);
	}
	str rotate_left(int x){
		string a = s.substr(0 , x);
		string b = s.substr(x);
		return str(b+a);
	}
	str trim_32(){
		string temp = s;
		reverse(temp.begin() , temp.end());
		temp = temp.substr(0 , 32);
		reverse(temp.begin() , temp.end());
		return str(temp);
	}
};
str h0 = str("01100111010001010010001100000001");
str h1 = str("11101111110011011010101110001001");
str h2 = str("10011000101110101101110011111110");
str h3 = str("00010000001100100101010001110110");
str h4 = str("11000011110100101110000111110000");
str k1 = str("01011010100000100111100110011001");
str k2 = str("01101110110110011110101110100001");
str k3 = str("10001111000110111011110011011100");
str k4 = str("11001010011000101100000111010110");
str f1(str B , str C , str D){
	str t = B&C;
	str t1 = !B;
	t1 = t1&D;
	t = t|t1;
	return t;
}
str f2(str B , str C , str D){
	str t = B^C;
	t = t^D;
	return t;
}
str f3(str B , str C , str D){
	str t = B&C;
	str t1 = B&D;
	str t2 = C&D;
	t = t|t1;
	t = t|t2;
	return t;
}
string binary_to_hex(string bin){
	int len = bin.size();
	string res = "";
	if(len%4 != 0){
		int pad = len%4;
		for(int i = 0 ; i < pad ; i++)
			bin = '0' + bin;
	}
	for(int i = 0 ,j = 0; i < bin.size() / 4 ;j+=4, i++){
		int x = (bin[j]-48)*8 + (bin[j+1] -48)*4 + (bin[j+2] - 48)*2 + (bin[j+3] - 48);
		res = res + hex_table[x];
	}
	return res;
}
string sha(string s){
	string text = "";
	for(int i = 0 ; i < s.size() ; i++){
		bitset<8> a((int)s[i]);
		text = text + a.to_string();
	}
	int len = text.size();
	text = text + '1';
	while(text.size()%512 != 448){
		text = text + '0';
	}
	bitset<64> a(len);
	text = text + a.to_string();
	len = text.size();
	for(int seg = 1 , pos = 0 ; seg <= len/512 ;pos += 512, seg++){
		string sub_text = "";
		sub_text = text.substr(pos , 512);
		vector<str> v;
		for(int i = 0, j = 0  ; i < 16 ;j+=32, i++){
			v.pb(str(sub_text.substr(j , 32)));
			// cout<<i<<" -> "<<v[i].s<<endl;
		}
		for(int i = 16 ; i < 80 ; i++){
			str temp = v[i-3]^v[i-8]^v[i-14]^v[i-16];
			v.pb(temp.rotate_left(1));
			// cout<<i<<" -> "<<v[i].s<<endl;
		}
		str A = h0 ,B  = h1, C = h2 , D = h3 ,E = h4;
		for(int i = 0 ; i < 80 ; i++){
			str f , k;
			if(i/20 < 1){
				f = f1(B , C , D);
				k = k1;
			} else if(i/20 < 2){
				f = f2(B , C , D);
				k = k2;
			} else if(i/20 < 3){
				f = f3(B , C , D);
				k = k3;
			} else if(i/20 < 4){
				f = f2(B , C , D);
				k = k4;
			}
			// cout<<"F -> "<<f.s<<endl<<"K -> "<<k.s<<endl;
			str temp = A.rotate_left(5) + f + E + k + v[i];
			// cout<<temp.s<<endl;
			temp = temp.trim_32();
			// cout<<" 32 bit -> "<<temp.s<<endl;
			E = D;
			D = C;
			C = B.rotate_left(30);
			B = A;
			A = temp;
		}
		h0 = h0 + A;h0 = h0.trim_32();
		h1 = h1 + B;h1 = h1.trim_32();
		h2 = h2 + C;h2 = h2.trim_32();
		h3 = h3 + D;h3 = h3.trim_32();
		h4 = h4 + E;h4 = h4.trim_32();
	}
	// cout<<h0.s<<endl<<h1.s<<endl<<h2.s<<endl<<h3.s<<endl<<h4.s<<endl;
	return binary_to_hex(h0.s + h1.s + h2.s + h3.s + h4.s);
}
int main(){
	string s;
	getline(cin , s);
	cout<<sha(s)<<endl;
	return 0;
}