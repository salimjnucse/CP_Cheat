#include<bits/stdc++.h>
using namespace std;
#define MXN 10000030
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

int wa[MXN],wb[MXN],wv[MXN],Ws[MXN], id[MXN];
int cmp(int *r,int a,int b,int l) {return r[a]==r[b] && r[a+l]==r[b+l];}

//(1-indexed) sa[i] = starting position (0...n-1) of ith lexicographically smallest suffix in s
//(0-indexed) Rank[i] = lexicographical rank of s[i....n-1] ((i+1)th suffix by position)
//LCP[i] = longest common prefix of sa[i] & sa[i-1]
int sa[MXN],Rank[MXN],LCP[MXN], n, window[20];

//Suffix Array (O(nlogn))
//m = maximum possible ASCII value of a string character (alphabet size)
//also, m = maximum number of distinct character in string (when compressed)
struct SuffixArrayLinear
{
    void buildSA(string s,int* sa,int n,int m)
    {
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++) Ws[i]=0;
        for(i=0; i<n; i++) Ws[x[i]=s[i]]++;
        for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
        for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
        for(j=1,p=1; p<n; j<<=1,m=p){
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) Ws[i]=0;
            for(i=0; i<n; i++) Ws[wv[i]]++;
            for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
            for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
        }
    }

    //Kasai's LCP algorithm (O(n))
    void buildLCP(string s,int *sa,int n)
    {
        int i,j,k=0;
        for(i=1; i<=n; i++) Rank[sa[i]]=i;
        for(i=0; i<n; LCP[Rank[i++]]=k)
            for(k?k--:0, j=sa[Rank[i]-1]; s[i+k]==s[j+k]; k++);
        return;
    }
};

int spt[MXN][20], lg[MXN];

struct Sparse_Table
{

    void initialize(){
        lg[1] = 0;

        FOR(i, 2, n){
    		lg[i] = lg[i / 2] + 1;
        }
    }

    void build_sparse_table(){
        initialize();
        /// max value sparse table
        /// it also used for  range MAX, MIN, OR, AND, GCD, LCM
        /// must change query
        for(int j = 0; j <= lg[n]; j++){
            for(int i = 1; i <=  n - (1 << j)  + 1; i++){
                if(j == 0) spt[i][j] = LCP[i];
                else{
                    spt[i][j] = min(spt[i][j - 1], spt[i + (1 <<(j - 1))][j - 1]);
                }
            }
        }
    }

    int query(int l, int r){
        int len = r - l + 1;
        int k = lg[len];
        return min(spt[l][k], spt[r - (1 << k) + 1][k]);
    }
};


void solve(int cs)
{
    int p = 0, sz, x = 1;
    cin >> n;
    int st = n;
    string s, ss;
    while(n--){
        cin >> ss;
        sz = ss.size();
        for(int i = 0; i < sz; i++){
            id[p++] = x;
        }
        s += ss;
        if(n >= 1) s += '#';
        p++;
        x++;
    }

    s += '$';

    n = s.size();
    SuffixArrayLinear SAL;
    SAL.buildSA(s,sa,n+1,130); //Important
    SAL.buildLCP(s,sa,n);

    int mx = 0, idx, lidx;
    
    for(int i = 1; i <= n; i++){
        cout  << id[sa[i]] << "  " << LCP[i] << "   ";
        for(int j = sa[i]; j < n; j++)cout << s[j];
        cout << endl;
    }
    cout << endl;

    Sparse_Table sp;

    sp.build_sparse_table();

    int window1 = st, window2 = st;

    int ans = 0;

    for(int i = st; i <= n; i++){
        int j;
        window[id[i]]++;
        for(j = 1; j <= st; j++){
            if(window[j] <= 0) break;
        }
        if(j > st){
            cout << window1 << " " << i << endl;
            ans = max(ans, sp.query(window1 + 1, i));
            window[window1]--;
            window1++;
        }
    }

    cout << endl;

    cout << ans << endl;

    return;
}

int main()
{
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif
    int t = 1, cs = 1;

    //cin >> t;

    while (t--){
        //cout << "Case " << cs << ": ";
        solve(cs++);
    }
}