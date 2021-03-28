#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

int const MXN = 2e5 + 10;

ll n, a[MXN], sgtree[4 * MXN];

struct SegmentTree
{
    ll marge(ll leftval, ll rightval)
    {
        return leftval + rightval;
    }

    void build(int node, int begin, int end)
    {
        if(begin == end){
            sgtree[node] = a[begin];
            return;
        }
        int mid = (begin + end) >> 1;

        build(node * 2, begin, mid);

        build(node * 2 + 1, mid + 1, end);
    
        sgtree[node] = marge(sgtree[node * 2], sgtree[node * 2 + 1]);
    }
    
    void update(int node, int begin, int end, int idx, int val)
    {
        if(begin == end){
            if(begin == idx) sgtree[node] = val;

            return;
        }

        if(idx < begin || idx > end) return;

        int mid = (begin + end) >> 1;

        update(node * 2, begin, mid, idx, val);

        update(node * 2 + 1, mid + 1, end, idx, val);

        sgtree[node] = marge(sgtree[node * 2], sgtree[node * 2 + 1]);
    }

    ll query(int node, int begin, int end, int i, int j)
    {
        if(begin > j || end < i) return 0;

        if(begin >= i && end <= j) return sgtree[node];

        int mid = (begin + end) >> 1;

        ll p = query(node * 2, begin, mid, i, j);
        ll q = query(node * 2 + 1, mid + 1, end, i, j);

        return marge(p, q);
    }
};


void solve(int cs)
{
    cin >> n;

    FOR(i, 1, n) cin >> a[i];

    SegmentTree st;

    st.build(1, 1, n);

    int q;

    cin >> q;

    while (q--)
    {
        int x, y;

        cin >> x >> y;

        cout << st.query(1, 1, n, x, y) << endl;
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

    while (t--)
        solve(cs++);
}
