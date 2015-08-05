#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
using namespace std;

inline bool leq(int a1, int a2, int b1, int b2)
{return(a1 < b1 || a1 == b1 && a2 <= b2); }
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3)); }
static void radixPass(int* a, int* b, int* r, int n, int K)
{
    int* c = new int[K + 1];
    for (int i = 0; i <= K; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[r[a[i]]]++;
    for (int i = 0, sum = 0; i <= K; i++)
    {int t = c[i]; c[i] = sum; sum += t; }
    for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
    delete [] c;
}
void suffixArray(int* s, int* SA, int n, int K) {
    int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
    int* s12 = new int[n02 + 3]; s12[n02]= s12[n02+1]= s12[n02+2]=0;
    int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
    int* s0 = new int[n0];
    int* SA0 = new int[n0];
    for (int i=0, j=0; i < n+(n0-n1); i++) if (i%3 != 0) s12[j++] = i;
    radixPass(s12 , SA12, s+2, n02, K);
    radixPass(SA12, s12 , s+1, n02, K);
    radixPass(s12 , SA12, s , n02, K);
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
        if (s[SA12[i]]!=c0 || s[SA12[i]+1]!=c1 || s[SA12[i]+2]!=c2)
        {name++; c0 = s[SA12[i]]; c1 = s[SA12[i]+1]; c2 = s[SA12[i]+2]; }
        if (SA12[i] % 3 == 1) { s12[SA12[i]/3] = name; }
        else {s12[SA12[i]/3 + n0] = name; }
    }
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    } else
        for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
    for (int i=0,j=0;i<n02;i++) if (SA12[i] < n0) s0[j++] = 3*SA12[i];
    radixPass(s0, SA0, s, n0, K);
    for (int p=0, t=n0-n1, k=0; k < n; k++) {
#define GetI() (SA12[t]<n0?SA12[t]*3 + 1 : (SA12[t]-n0)*3 + 2)
        int i = GetI();
        int j = SA0[p];
        if (SA12[t] < n0 ?
                leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
                leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
        { SA[k] = i; t++;
            if (t == n02)
                for (k++; p < n0; p++, k++) SA[k] = SA0[p];
        } else {SA[k] = j; p++; if (p == n0)
            for (k++; t < n02; t++, k++) SA[k] = GetI();
        }
    }
    delete [] s12;
    delete [] SA12;
    delete [] SA0;
    delete [] s0;
}

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ASSERT(A,p,q) assert(p <= A && q >= A)

int L[100010], RR[100010];
void LCP(int y[], int p[], int n)
{
    FOR(i,0,n) RR[p[i]] = i;
    int l = 0;
    FOR(j,0,n)
    {
        l = max(0,l-1);
        int i = RR[j];
        if(i)
        {
            int J = p[i-1];
            while (j+l < n && J+l < n && y[j+l] == y[J+l]) l++;
        }
        else l = 0;
        L[i] = l;
    }
    L[n] = 0;
}

int N;
int A[100010];
int D[100010];
int S[100010];
int main()
{
    int T;
    scanf("%d",&T);
    ASSERT(T,1,1000);
    int su = 0;
    while(T--) {
        scanf("%d",&N);
        ASSERT(N,1,100000);
        su += N;
        FOR(i,0,N) {
            scanf("%d",&A[i]);
            ASSERT(A[i],-1000000,1000000);
        }
        // DOES THIS CASE REALLY MAKE SENSE?
        if(N == 1) {
            printf("0\n");
            continue;
        }
        if(N == 2) {
            printf("1\n");
            continue;
        }
        FOR(i,1,N) {
            D[i-1] = A[i]-A[i-1];
            ASSERT(D[i-1],-100,100);
        }
        int mi = 101, ma = -101;
        FOR(i,0,N-1) if(D[i] < mi) mi = D[i];
        FOR(i,0,N-1) {
            D[i] -= mi-1;
            if(D[i] > ma) ma = D[i];
        }
        //FOR(i,0,N-1) printf("%d ",D[i]); printf("\n");
        suffixArray(D,S,N-1,ma);
        //FOR(i,0,N-1) printf("%d ",S[i]); printf("\n");
        LCP(D,S,N-1);
        //FOR(i,0,N-1) printf("%d ",L[i]); printf("\n");
        int res = 0;
        FOR(i,0,N-1) {
            res += N-S[i]-1-L[i];
            // THIS IS BREAKING SOMETHING IN THE PROBLEM STATEMENT
            res %= 1000000009;
        }
        printf("%d\n",res);
    }
    ASSERT(su,1,100000);
    return 0;
}
