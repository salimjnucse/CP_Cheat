#include <bits/stdc++.h>
using namespace std;

typedef long long ll
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
int const MXN = 2e3 + 5; // check your array size
ll a[MXN][MXN], bit[MXN][MXN];

struct FenwickTree2D
{
    int lowbit(int x){return x & -x;}

    void update(int x, int y, ll val)
    {
        if(x <= 0 || y <= 0) return;
        while (x < MXN)
        {
            int _y = y;
            while (_y < MXN)
            {
                bit[x][_y] += val;
                _y += lowbit(_y);
            }
            x += lowbit(x);
        }
    }

    ll query(int x, int y)
    {
        ll ret = 0;
        while (x > 0)
        {
            int _y = y;
            while (_y > 0)
            {
                ret += bit[x][_y];
                _y -= lowbit(_y);
            }
            x -= lowbit(x);
        }
        return ret;
    }
    ll rangeQuery(int x1, int y1, int x2, int y2)
    {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

void solve(int cs)
{
    int n, m, q;
    cin >> n >> m >> q;

    FOR(i, 0, MXN - 1){
        FOR(j, 0, MXN - 1){
            bit[i][j] = 0;
        }
    }

    FenwickTree2D fwt;

    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> a[i][j];

            fwt.update(i, j, a[i][j]);
        }
    }

    while (q--)
    {
        int type;

        cin >> type;

        if(type == 1){
            int x, y, val;
            cin >> x >> y >> val;

            fwt.update(x, y, val);
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            ll ans = fwt.rangeQuery(x1, y1, x2, y2);

            cout << ans << endl;
        }
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

    //cin >> t;

    while (t--){
        solve(cs++);
    }
}
