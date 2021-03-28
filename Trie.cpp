#include<bits/stdc++.h>
using namespace std;

int const MXN = 1e4;

struct trie{

    int node[MXN][26], cnt[MXN], totnode;

    void initialize()
    {
        totnode = 1;
        memset(node, 0, sizeof node);
        memset(cnt, 0, sizeof cnt);
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

    int query(string s)
    {
        int cur = 1;

        for(int i = 0; i < s.size(); i++){
            int ch = s[i] - 'a';

            if(!node[cur][ch]) return 0;

            cur = node[cur][ch];
        }

        return cnt[cur];
    }
};

void solve(int cs)
{
    int n, q;

    cin >> n >> q;

    string s;

    trie tt;

    tt.initialize();

    for(int i = 0; i < n; i++){
         cin >> s;

         tt.add_string(s);
    }

    while(q--){
        cin >> s;

        cout << tt.query(s) << endl;
    }

    return;
}

int main()
{
    int t = 1, cs =  1;

    cin >> t;

    while(t--) solve(cs++);
}
