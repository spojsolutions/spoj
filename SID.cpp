/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 October 2015 (Saturday) 08:52
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void scanchar(char &c){
    register int x = gc();
    for(;(x < 65 || x > 97);x = gc());
    c = x;
}
int main(){
    
    int n , m , temp;
    scanint(n);
    scanint(m);
    unordered_multimap<int , int > save;
    for(int i = 1 ; i<= n ; i++){
        scanint(temp);
        save.insert(mp(temp , i));
    }
    int val;
    char type;
    int initial_size = n;
    while(m--){
        scanchar(type);
        if(type == 'S'){
            scanint(val);
            auto it = save.equal_range(val);
            if(it.first != save.end()){
                auto x = it.first;
                auto y = it.first;
                y++;
                while(y!= it.second){
                    x = y;
                    y++;
                }
                printf("%d\n" , x->second);
            } else{
                printf("NONE\n");
            }
        } else if(type == 'I'){
            scanint(val);
            initial_size++;
            save.insert(mp(val , initial_size));//₹₹₹₹₹₹₹₹₹₹₹₹
            printf("%d\n",initial_size);
        } else {
            scanint(val);
            auto it = save.equal_range(val);
            if(it.first!= save.end()){
                auto x = it.first;
                auto y = it.first;
                y++;
                while(y!= it.second){
                    x = y;
                    y++;
                }
                printf("%d\n" , x->second);
                save.erase(x);
            } else{
                printf("NONE\n");
            }
        }
    }
    return 0;
} 