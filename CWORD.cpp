#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int s=1;s<=t;s++)
    {
        int n,k,q,temp;
        scanf("%d%d",&n,&k);
        int stage[n+9][k+9],cost[n+9][k+9];
        for(int i=0;i<=n;i++)
            for(int j = 0;j<=k;j++)
                stage[i][j] = 0,cost[i][j] = INT_MIN;
        vector<int> v[n+9];
        v[0].push_back(0);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q);
            for(int j=0;j<q;j++) {
                scanf("%d", &temp);
                if(!stage[i+1][temp])
                {
                    v[i+1].push_back(temp);
                    stage[i+1][temp] = 1;
                }
            }
            v[i+1].push_back(0);
        }
        int colour[k+9][k+9];

        for(int i=0;i<=k;i++) // init. of first row and first coloumn 
            colour[0][i] = colour[i][0] = 0; 

        for(int i=1;i<=k;i++)
            for(int j = 1;j<=k;j++)
                scanf("%d",&colour[i][j]);

        for(int i=0;i<v[n].size();i++) // initalization of last level of cost;
            cost[n][v[n][i]] = 0;

        for(int i = n-1;i>=0;i--)// multi stage logic
        {
            for(int j=0;j<v[i].size();j++)
            {
                for(int l = 0;l<v[i+1].size();l++){
                    cost[i][v[i][j]] = max(cost[i][v[i][j]] , colour[v[i][j]][v[i+1][l]] + cost[i+1][v[i+1][l]]);
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
                cout<<cost[i][j]<<"  ";
            cout<<endl;
        }
        printf("Game %d: %d\n",s,cost[0][0]);
    }
    return 0;
}