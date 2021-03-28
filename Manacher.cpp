#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

int const MXN = 1e6 + 10;

int n, P[MXN];

struct Manacher
{
    string get(string &s)
    {
        string r = "";
        r += '#';
        for(int i = 0; i < s.length(); i ++ ) {
                r += s[i];
                r += '#';
        }
        return r;
    }
    void build_manacher(string s)
    {
        s = get(s);
        cout << s << endl;

        n = s.size();

        int R = 0, C = 0;
        int MaxLen = 0, Index;

        for(int i = 0 ; i < s.length() ; i ++ ) {
            int iPrime = 2 * C - i;
            P[i] = (R > i) ? min(R-i, P[iPrime]) : 0;
            
            while(i + 1 + P[i] < s.length() && s[i + 1 + P[i]] == s[i-1-P[i]]) P[i]++;
            
            if(i + P[i] > R ) {
                    C = i;
                    R = i + P[i];
            }

            MaxLen = max(MaxLen, P[i]);
            if(P[i] == MaxLen) {
                    Index = i;
            }
        }
        return;
    }
};


void solve(int cs)
{
    cin >> n;

    string s;

    cin >> s;

    Manacher manacher;

    manacher.build_manacher(s);

    FOR(i, 0, n - 1) cout << P[i];
    cout << endl;
    
    return;
}

int main()
{
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif
    int t = 1, cs = 1;

    cin >> t;

    while (t--){
        //cout << "Case " << cs << ": ";
        solve(cs++);
    }
}
