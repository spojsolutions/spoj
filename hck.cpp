#include <cstdio>
#define vs vector<string>
char v[10][11];
bool check( int row , int col , int n , int m){
    //int n = v.size() , m = v[0].size();
    int i = row-1 , j = col-1;
    if(v[row][col] == '*')
        return false;
    // while(i >=0 && j >=0){
    //     if(v[i][j] == 'b')
    //         return false;
    //     if(v[i][j] == '*')
    //         break;
    //     i-- , j--;
    // }
    // i = row-1 , j = col+1;
    // while(i>=0 && j < m){
    //     if(v[i][j] == 'b')
    //         return false;
    //     if(v[i][j] == '*')
    //         break;
    //     i-- , j++;
    // }

    return true;
}
void dfs(int row ,int bcount, int &count , int n , int m){
    if(bcount == n){
        count++;
        return ;
    }
    for(int i = 0 ; i < m ; i++){
        if(v[row][i] == '.'){
            v[row][i] = 'b';
            check(row, i);
            dfs(row+1 , bcount+1 , count , n , m);
            v[row][i] = '.';
        }
    }
}

int main() {
    int n , m;
    //cin>>n>>m;
    scanf("%d%d",&n , &m);
    //string s[n+9];
    //vector<string> v;
    for(int i = 0 ; i < n ; i++){
        scanf("%s" , v[i]);
    }
    int count = 0;
    dfs( 0 , 0 , count , n , m);
    printf("%d\n" , count);
    return 0;
}
