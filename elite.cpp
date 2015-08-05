#include <bits/stdc++.h>
#define MOD 1000000009
#define mul 15485863
#define LL long long
#define pb push_back
using namespace std;
struct point{
    int x , y;
    point(){}
    point(int a , int b){
        x = a , y = b;
    }
};
struct data{
    point l , r;
    data(){}
    data(point a , point b){
        l.x = a.x ,l.y = a.y , r.x = b.x , r.y = b.y;
    }
};
vector<data> rec;
bool check(data d){
    bool flag = 0;
    for(int i = 0 ; i < rec.size() ; i++){
        if(d.l.x >= rec[i].l.x && d.l.y >= rec[i].l.y && d.l.x <= rec[i].r.x && d.l.y <= rec[i].r.y){
            flag = 1;
            break;
        }
        if(d.l.x <= rec[i].r.x && d.l.x >= rec[i].l.x && d.r.y >= rec[i].l.y && d.r.y <= rec[i].r.y){
            flag = 1 ;
            break;
        }
        if(d.l.x >= rec[i].l.x && d.l.x <= rec[i].r.x && d.l.y >= rec[i].l.y && d.l.y <= rec[i].r.y){
            flag = 1;
            break;
        }
        if(d.r.x <= rec[i].r.x && d.r.x >= rec[i].l.x && d.l.y >= rec[i].l.y && d.l.y <= rec[i].r.y){
            flag = 1;
            break;
        }
    }
    rec.pb(d);
    return (flag^1);
}
LL Hash[1009][1009];
void solve(){
    int n , m , r , c;
    cin>>n>>m;
    char text[n+9][m+9];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin>>text[i][j];
    memset(Hash , 0 , sizeof Hash);
    for(int i = n-1 ; i>=0 ; i--){
        for(int j = m-1 ; j>= 0 ; j--){
            Hash[i][j] = ((Hash[i][j+1]*mul)%MOD + (text[i][j] - 48))%MOD;
        }
    }
    int q;
    cin>>q;
    while(q--){
        rec.clear();
    cin>>r>>c;
    char patt[r+9][c+9];
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++)
            cin>>patt[i][j];
    LL pat[r+9];
    LL val = 1;
    memset(pat , 0 , sizeof pat);
    int flag = 1;
    for(int i = r-1 ; i>=0 ; i--){
        for(int j = c-1 ; j>=0 ; j--){
            pat[i] = ((pat[i]*mul)%MOD + (patt[i][j] - 48))%MOD;
        }
    }
    
    for(int i = 1 ; i<= c ; i++){
        val = (val*mul)%MOD;
    }
    flag = 1;
    int count = 0;
    for(int i = 0 ; i < n - r + 1; i++){
        for(int j = 0 , k = 0 ; j< m - c +1 ;k++, j++){
            flag = 1;
            if(((Hash[i][j] - (val*Hash[i][j+c])%MOD + MOD)%MOD) == pat[0]){
                for(int l = i , p = 0 ; l < r + i && l < n  ;p++ , l++){
                    if(((Hash[l][j] - (val*Hash[l][j+c])%MOD + MOD)%MOD) != pat[p]){
                        flag = 0;
                    }
                }
                if(flag){
                    //cout<<j << " " << i << " " << j + c -1 << " " <<i + r  - 1<<endl;
                    if(check(data(point(j , i ) , point(j+c-1 , i+r-1))))
                        count++;
                }
            }
        }
    }
    cout<<count<<endl;}
}

int main() {
    solve();  
    return 0;
}
