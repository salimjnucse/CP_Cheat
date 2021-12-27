#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
int const MXN = 1e6 + 5; // check your array size
ll a[MXN], bit[MXN], n, q;

struct FenwickTree
{
    int lowbit(int x) {return x & -x;}

    void update(int idx, ll val)
    {
        if(idx <= 0) return;
        while (idx < MXN)
        {
            bit[idx] += val;
            idx += lowbit(idx);
        }
    }

    void rangeupdate(int l, int r, ll val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    ll query(int idx)
    {
        ll ret = 0;
        while (idx > 0)
        {
            ret += bit[idx];
            idx -= lowbit(idx);
        }
        return ret;
    }

    ll rangequery(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};


void solve(int cs)
{
    cin >> n >> q;

    FenwickTree fwt;

    FOR(i, 1, n){
        cin >> a[i];

        fwt.update(i, a[i]);
    }

    while (q--)
    {
        int type;
        cin >> type;

        if(type == 1){
            ll idx, val;
            cin >> idx >> val;

            fwt.update(idx, val);
        }
        else{
            int l, r;

            cin >> l >> r;

            ll ans = fwt.rangequery(l, r);

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

    cin >> t;

    while (t--){
        solve(cs++);
    }
}
