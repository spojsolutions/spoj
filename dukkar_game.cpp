#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        map<string , int> m;
        map<string , int>::iterator t;
        for(int i = 0 ; i < n ; i++){
            int temp;
            cin>>s>>temp;
            m[s]+=temp;
        }
       string name;
        int mx = -1;
        for(t = m.begin() ; t!=m.end() ;t++){
            if(t->second > mx){
                mx = t->second;
                name = t->first;
            }
        }
        cout<<name<<" "<<mx<<endl;
    }
    return 0;
}
