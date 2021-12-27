#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 10000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
int const MXN = 2e5 + 5;

int node[MXN][26], cnt[MXN], totnode, dpt[MXN], pl[MXN], par[MXN], fail[MXN];
struct Aho_Corasick{
    void initialize()
    {
        totnode = 1;
        for(int i = 0; i < MXN; i++){
            cnt[i] = dpt[i] = pl[i] = par[i] = 0;
        }
    }

    void add_string(string s)
    {
        int cur = 1;

        cnt[cur]++;

        for(int i = 0; i < s.size(); i++){
            int ch = s[i] - 'a';

            if(!node[cur][ch]) node[cur][ch] = ++totnode;

            cur = node[cur][ch];

            cnt[cur]++;
        }
    }

    void build_fail()
    {
        queue < int > q;
        q.push(1);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(dpt[u] <= 1){
                fail[u] = 1;
            }
            else{
                int v = fail[par[u]], l = pl[u];

                while(v > 1 && node[v][l] == 0) v = fail[v];

                if(node[v][l]) v = node[v][l];

                fail[u] = v;
            }

            for(int i = 0; i < 26; i++){
                if(node[u][i]) q.push(node[u][i]);
            }
        }
    }
};

void solve(int cs)
{
    string s;

    int q = 4;
    Aho_Corasick aho;
    aho.initialize();
    while (q--)
    {
        cin >> s;

        aho.add_string(s);

    }
    aho.build_fail();

    FOR(i, 1, 30) cout << fail[i] << " ";
    cout << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif
    int t = 1, cs = 1;
    cin >> t;

    while (t--){
       solve(cs);
    }
}
