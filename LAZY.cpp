#include <bits/stdc++.h>
using namespace std;
 
int T,n,m,i,j,k;
int q[50005],l,r;
char s[50005];
long long ans,tmp,lnum,rnum,L,R;
 
int main()
{
    scanf("%d",&T);
    for(;T;--T)
    {
        scanf("%d",&m);
        scanf("%s",s+1);
        n=strlen(s+1);
        l=1;r=0;
        for(i=1;i<=n;++i)
        if(s[i]=='1')
        {
            q[++r]=i;
            if(r==m)break;
        }
        k=1+m>>1;L=R=0;
        for(j=1;j<k;++j)L+=q[j];
        for(j=k+1;j<=m;++j)R+=q[j];
        lnum=k-1;rnum=m-k;
        ans=lnum*q[k]-L+R-rnum*q[k];
        cout<<"1 -> "<<ans<<endl;
        int p = 2;
        for(++i;i<=n;++i)
        if(s[i]=='1')
        {
            q[++r]=i;
            L-=q[l++];L+=q[k++];
            R-=q[k];R+=q[r];
            tmp=lnum*q[k]-L+R-rnum*q[k];
            cout<<p<<" -> "<<tmp<<endl;
            if(tmp<ans)ans=tmp;
            p++;
        }
        cout<<ans<<endl;
        ans-=(lnum+1)*lnum/2+(rnum+1)*rnum/2;
        printf("%lld\n",ans);
    }
}
