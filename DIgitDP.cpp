#include <bits/stdc++.h>
using namespace std;

                                // Total number of zero in 0 to n

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define mod 1000000007

int const MXN = 1000;
string s;

ll dp[12][3][3], n, dp2[12][3];

ll fnc2(int pos, int is_small)
{
    if(pos >= 10) return 1;
    if(dp2[pos][is_small] != -1) return dp2[pos][is_small];

    int lo = 0, hi = s[pos] - '0';

    if(is_small) hi = 9;

    ll ret = 0;

    FOR(i, lo, hi){
        ret += fnc2(pos + 1, is_small | (i < hi));
    }

    return dp2[pos][is_small] = ret;
}

ll fnc(int pos, bool is_small, bool is_started)
{
    if(pos >= 10) return 0;

    if(dp[pos][is_small][is_started] != -1) return dp[pos][is_small][is_started];

    int lo = 0, hi = s[pos] - '0';
    if(is_small) hi = 9;

    /* int lo = ss[pos] - '0', hi = s[pos] - '0';
    if(is_small) hi = 9;
    if(is_big) lo = 0; */

    ll ret = 0;

    FOR(i, lo, hi){
        ret += fnc(pos + 1, is_small | (i < hi), is_started | i);

        if(is_started && i == 0) ret += fnc2(pos + 1, is_small | (i < hi));
    }

    return dp[pos][is_small][is_started] = ret;
}

void solve(int cs)
{
    cin >> s;

    int sz = 10 - s.size();

    string ss = "";

    while (sz--)
    {
        ss += '0';
    }
    
    s = ss + s;

    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);

    cout << s << endl << fnc(0, 0, 0) << endl;

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

    while (t--)
        solve(cs++);
}
