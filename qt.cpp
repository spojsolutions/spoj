#include <bits/stdc++.h>
using namespace std;
long long tree[10009] , l[10009];
long long dist[10009] , visited[10009];
long long sparse[10009][22];

void lcaPrecomputation(long long n){
    for(int i = 1 ; i <= n ; i++)
        sparse[i][0]= tree[i];
 
    for(int j = 1 ; (1<<j) <= n ; j++){
        for(int i = 1 ; i <= n ; i++)
            if(sparse[i][j-1] != -1){
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];      
            }        
    }
}
int LCA(int u , int v ){
 
    if(l[u] < l [v])
        swap(u , v);
 
    int log_len;
    for(log_len = 1 ; (1<<log_len)<=l[u] ; log_len++);
        log_len--;
    for(int i = log_len ; i>=0 ;i--)
        if(l[u] - (1<<i) >= l[v]){
            u = sparse[u][i];
        }
    if(u == v)
        return u;
    for(int i = log_len ; i>=0 ; i--)
        if(sparse[u][i] != -1 && sparse[u][i] != sparse[v][i]){
            u = sparse[u][i] , v = sparse[v][i] ;
        }
    return tree[u];
}
 
 
void dfs(vector<long long> vec[] ,vector<long long> dist_vec[], int node){
    visited[node] = 1;
    for(int i = 0 ; i < vec[node].size() ; i++){
        if(!visited[vec[node][i]]){
            dist[vec[node][i]] = dist[node] + dist_vec[node][i];
            l[vec[node][i]] = l[node] + 1;
            tree[vec[node][i]] = node;
            dfs(vec , dist_vec  ,vec[node][i]);
        }    
    }
}
 
 
int main(){
    int t;
    scanf(" %d",&t);
    char str[20];
    while(t--){
        vector<long long> vec[10009] , dist_vec[10009];
        long long n;
        scanf(" %lld",&n);
        int p , q , w;
        memset(tree , -1 , sizeof tree);
        memset(dist , 0 , sizeof dist);
        memset(sparse , -1 , sizeof sparse);
        memset(visited , 0 , sizeof visited);
        memset(l , 0 , sizeof l);
        for(int i = 0 ; i < n-1 ; i++){
            scanf(" %d %d %d",&p,&q,&w);
            vec[p].push_back(q);
            dist_vec[p].push_back(w);
        }
        int root = 1;
        dist[root] = 0;
        tree[root] = -1;
        l[root] = 0;
        dfs(vec , dist_vec ,root);
        lcaPrecomputation(n);
        while(true){
            long long total = 0 ;
            
            scanf("%s ",str);
            if(str[0] == 'D' && str[1] == 'I'){
                int u ,v;
                scanf(" %d %d",&u ,&v);
                int lca = LCA(u , v);
                total = l[u] + l[v] - 2*l[lca];
                printf("%lld\n",total);
            }  
            else if(str[0] == 'D' && str[1] == 'O')
                break;
            else if(str[0] == 'K'){
                int u , v , k;
                long long path_len;
                scanf(" %d %d %d",&u , &v ,&k);
                int lca = LCA(u , v);
                if(lca == u)
                {
                    path_len = l[v] - l[u] +1;
                    swap(u , v);
                    k = path_len - k + 1;
                }
                else if(lca == q);
                else{
                    if(l[u] - l[lca] + 1 < k){
 
                        path_len = l[u] + l[v] -2*l[lca] +1;
                        k = path_len - k + 1;
                        swap(u , v);
                    }
                }
                int i = 0;
                k--;
                assert(k>=0);
                while(k){
                    if(k&1)
                        u = sparse[u][i];
                    i++;
                    k>>=1; 
                }
                printf("%d\n",u);
                // if(l[u] - l[lca] + 1 < k){
                //     k = path_len - k;
                //     assert(k >= 0);
                //     int i = 0;
                    
                //     while(k){
                //         if(k&1)
                //             v = sparse[v][i];
                //         k>>=1;
                //         i++;                    
                //     }
                //     printf("%d\n",v);          
                // }
                // else{
                //     k--;
                //     int i = 0;
                    
                //     while(k){
                        
                //         if(k&1)
                //             u = sparse[u][i];
                //         k>>=1;
                //         i++;                    
                //     }
                //     printf("%d\n",u);
                // }          
            }     
        }
    }
    return 0;
}