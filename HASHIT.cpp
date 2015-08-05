/* Talent hits a target no one else can hit. Genius hits a target no one else can see*/

#include <bits/stdc++.h>
using namespace std;
int get_hash(string s){
	int key = 0;
	for(int i = 0 ; i < s.size() ; i++){
		key += (i+1)*(s[i]);
	}
	return (key*19)%101;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int q;
		cin>>q;
		map<string , int> first;
		map<int , string> key_map;
		while(q--){
			string s;
			cin>>s;
			if(s[0]=='A'){
				s = s.substr(4);
				if(first.find(s) != first.end()) continue;
				for(int i = 0 ; i < 20 ; i++){
					int key = (i*i + 23*i + get_hash(s))%101;
					if(key_map.find(key) == key_map.end()){
						first[s] = key;
						key_map[key] = s;
						break;
					}
				}
			} else if(s[0] == 'D'){
				s = s.substr(4);
				if(first.find(s) == first.end()) continue;
				int key = first[s];
				first.erase(s);
				key_map.erase(key);
			}
		}
		cout<<key_map.size()<<endl;
		for(auto t = key_map.begin() ; t!= key_map.end() ; t++){
			cout<<t->first<<":"<<t->second<<endl;
		}
	}
	return 0;
}