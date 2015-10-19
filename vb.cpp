#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pll pair < long long , long long >
#define ll long long
long long orientation(pll P,pll Q,pll R){
    return  (Q.first-P.first)*(R.second-P.second)-(R.first-P.first)*(Q.second-P.second);
}
int slope_compare(pll &a , pll &b , pll &c , pll &d){
    if((b.second - a.second)*(d.first - c.first) > (b.first - a.first)*(d.second - c.second))
        return 1;
    return 0;
}
void convex_hull(vector<pll > &P,vector<pll > &l,vector<pll > &u){
    int j=0,k=0,n=P.size();
    sort(P.begin(),P.end());
    u.resize(2*n);
    l.resize(2*n);
    for(int i=0;i<n;i++)
    {
        while(j>=2 && orientation(l[j-2],l[j-1],P[i])<=0)
            j--;
        while(k>=2 && orientation(u[k-2],u[k-1],P[i])>=0)
            k--;
        l[j++]=P[i];
        u[k++]=P[i];
    }
    u.resize(k);
    l.resize(j);
}
long long Dist(pll P ,pll Q){
    return abs(P.first*P.first - Q.first*Q.first)+abs(P.second*P.second - Q.second*Q.second);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<pll >v,u,l;
        int n;
        scanf("%d",&n);
        int k1;
        for(int i=0;i<n;i++){
            scanf("%d",&k1);
            v.push_back(make_pair(i+1,k1));
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        convex_hull(v,l,u);
        int i = 0 , j = l.size() -1;
        ll ans = 0;
        while( i < u.size()-1 || j > 0){
            ans = max(ans , Dist(u[i] , l[j]));
            if( i == u.size()-1)
                j--;
            else if( j == 0 )
                i++;
            else if(slope_compare(u[i] , u[i+1] , l[j-1] , l[j]))
                i++;
            else
                j--;
        }
        for(int i = 0 ; i < u.size() ; i++){
            for(int j =i + 1 ; j<u.size() ; j++){
                ans = max(ans , Dist(u[i] , u[j]));
            }
        }
        for(int i = 0 ; i < l.size() ; i++){
            for(int j =i + 1 ; j<l.size() ; j++){
                ans = max(ans , Dist(l[i] , l[j]));
            }
        }
        printf("%lld\n", ans);
    }
}