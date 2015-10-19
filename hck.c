#include <stdio.h>
int v[10][11];
#define true 1
#define false 0
int count = 0;
int n, m;
void check( int row , int col , int c){
    int i = row+1 , j = col+1;
    while (i < n && j < m){
        if (v[i][j] == -1) break;
        v[i][j] += c;
        i++; j++;
    }
    i = row + 1; j = col - 1;
    while (i < n && j >= 0){
        if (v[i][j] == -1) break;
        v[i][j] += c;
        i++; j--;
    }
}

void dfs(int row ,int bcount){
    int i, k, j;
    for(i = 0 ; i < m ; i++){
        if(v[row][i] == 0){
            if (bcount == n-1){
                ++count;
                continue;
            }
            v[row][i] = 1;
            check(row, i, 1);
            dfs(row+1 , bcount+1 );
            v[row][i] = 0;
            check(row, i, -1);
        }
    }
}

int main() {
    int j,i;
    scanf("%d%d",&n , &m);
    char x[n + 1][m + 1];
    for( i = 0 ; i < n ; i++){
        scanf("%s" , x[i]);
    }
    for ( i = 0; i<n; i++){
        for (j = 0; j<m; j++){
            if (x[i][j] == '.') v[i][j] = 0;
            else v[i][j] = -1;
        }
    }
    dfs( 0 , 0 );
    printf("%d\n" , count);
    return 0;
}
