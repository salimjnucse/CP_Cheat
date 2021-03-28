#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const MXN = 1e3 + 10;

ll n, a[MXN][MXN], b[MXN], m, k, d, prefix[MXN][MXN], q;

struct PrefixSum2D
{
    void initialize()
    {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] = 0;
            }
        }
    }
    ll calculate(ll x, ll y)
    {
        return a[x][y] + prefix[x-1][y] + prefix[x][y-1] - prefix[x-1][y-1];
    }

    ll query(ll x1, ll y1, ll x2, ll y2)
    {
        return prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1];
    }

    void build()
    {
        initialize();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] = calculate(i, j);
            }
        }
    }
};


void solve(int cs)
{
    PrefixSum2D ps;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    ps.build();

    cin >> q;

    ll x1, y1, x2, y2;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        ll x = ps.query(x1, y1, x2, y2);

        cout << x << endl;
    }

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

    while (t--)
        solve(cs++);
}
