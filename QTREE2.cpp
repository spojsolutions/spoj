#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 10009
#define LOG_MAX 14
struct data{
    int ff , ss;
    data(int a , int b){ ff = a , ss = b;}
};
int S[MAXLEN][LOG_MAX] , L[MAXLEN] , tree[MAXLEN] , visited[MAXLEN] , n;
long long dist[MAXLEN];

void dfs(vector<data> v[] , int node){

    visited[node] = 1;
    for(int i = 0 ; i < v[node].size() ; i++){
        if(!visited[v[node][i].ff]){
            dist[v[node][i].ff] = dist[node] + v[node][i].ss;
            L[v[node][i].ff] = L[node] + 1;
            tree[v[node][i].ff] = node;
            dfs(v ,v[node][i].ff);
        }
    }
}
void preComputation(){
    memset(S , -1 , sizeof S);
    for(int i = 1 ; i<= n ; i++)
        S[i][0] = tree[i];
    for(int j = 1 ; (1<<j) <= n ; j++) 
        for(int i = 1 ; i<= n ; i++)
            if(S[i][j-1]!= -1)
                S[i][j] = S[S[i][j-1]][j-1];
}
int lcaQuery(int u , int v){

    if(L[u] < L[v])
        swap(u , v);

    int log_len;

    for(int log_len = 1 ; (1<<log_len) <= L[u] ; log_len ++);
    log_len--;
    
    for(int i = log_len ; i>=0 ; i--)
        if(L[u] - (1<<i) >= L[v])
            u = S[u][i];
    if(u == v)
        return u;
    for(int i = log_len ; i>= 0 ; i--)
        if(S[u][i] != -1 && S[u][i] != S[v][i])
            u = S[u][i] , v = S[v][i];
    return tree[u];
}
string get_type(char s[]){

    string temp="";
    int i =0 ;
    while(s[i] != 32){
        char c = s[i];
        temp= temp + c;
        i++;
    }
    return temp;
}
int get_u(char s[])
{
    int i = 0 , res = 0;
    while(s[i] != ' ')
        i++;
    i++;
    while(s[i] != ' '){
        res = res *10 + (s[i] - 48);
        i++;
    }
    return res;
}
int get_v(char s[]){
    int i = 0 , cnt = 0 , res=0;
    while(s[i] != '\n'){
        if(s[i] == ' ')
            cnt++;
        if(cnt == 2)
            break;
        i++;
    }
    i++;
    while(s[i] != '\0' && s[i] != ' '){
        res = res*10 + (s[i] - 48);
        i++;
    }
    return res;
}
int get_k(char s[]){

    int i = 0 , cnt = 0 , res = 0;
    while(true){
        if(s[i] == ' ')
            cnt++;
        if(cnt == 3)
            break;
        i++;
    }
    i++;
    while(s[i] != '\0' && s[i] != ' '){
        res = res*10 + (s[i] - 48);
        i++;
    }
    return res;
}
int main(){
    char s[30];
    int t; 
    scanf(" %d",&t);
    while(t--){
        memset(visited , 0 , sizeof visited);
        memset(dist , 0 , sizeof dist);
        memset(L , 0 , sizeof L);
        memset(tree , 0 , sizeof tree);
        vector<data> v[MAXLEN];
        scanf(" %d" ,&n);
        for(int i = 0 ; i < n-1 ; i++){
            int p , q , w;
            scanf(" %d %d %d",&p , &q , &w);
            v[p].push_back(data(q , w));
            v[q].push_back(data(p , w));
        }
        int total_len=0;
        int root = rand() % n + 1;;
        dist[root] = 0;
        L[root] = 0;
        tree[root] = -1;
        dfs(v , root);
        preComputation();
        gets(s);
        while(gets(s)){
            if(s[1] == 'O') break;
            int u = get_u(s);
            int v = get_v(s);
            int lca = lcaQuery(u , v);
            string type = get_type(s);
            if(type == "DIST")
                printf("%lld\n",dist[u] + dist[v] - 2*dist[lca]);
            else if(type == "KTH"){
                int k = get_k(s);
                if(u == lca){
                    total_len = L[v] - L[u] + 1;
                    k = total_len - k +1;
                    swap(u , v);
                }
                else if (v == lca);
                else{
                    if(L[u] - L[lca] + 1 < k){
                        total_len = L[u] + L[v] - (2*L[lca]) + 1;
                        assert(total_len>= k);
                        k = total_len - k + 1;
                        swap(u , v);
                    }
                }
                k--;
                //assert(k>=0);
                int log_len ;
                for(log_len = 1 ; (1<<log_len) <= L[u] ; log_len++);
                log_len--;
                for(int i = log_len ; i>=0 ; i--){
                    if((1<<i) <= k){
                        u = S[u][i];
                        k-=(1<<i);
                    }
                }

                printf("%d\n",u);
            }
        }
    }
    return 0;
}