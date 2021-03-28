#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

int const MXN = 2e5 + 10;

ll n, a[MXN], sgtree[4 * MXN], lazy[4 * MXN];

struct SegmentTree
{
    int marge(int lftval, int rightval)
    {
        return lftval + rightval;
    }

    void relax(int node, int begin, int end)
    {
        if(!lazy[node]) return;

        if(begin == end){
            sgtree[node] += lazy[node];
        }
        else{
            ll len = end - begin + 1;

            sgtree[node] += len * lazy[node];

            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
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

    void update(int node, int begin, int end, int i, int j, ll val)
    {
        relax(node, begin, end);

        if(begin >= i && end <= j){

            lazy[node] += val;

            relax(node, begin, end);
            
            return;
        }

        if(begin > j || end < i) return;

        int mid = (begin + end) >> 1;

        update(node * 2, begin, mid, i, j, val);

        update(node * 2 + 1, mid + 1, end, i, j, val);

        sgtree[node] = marge(sgtree[node * 2], sgtree[node * 2 + 1]);
    }

    int query(int node, int begin, int end, int i, int j)
    {
        relax(node, begin, end);
        
        if(begin > j || end < i){
            return 0;
        }

        if(begin >= i && end <= j){
            return sgtree[node];
        }

        int mid = (begin + end) >> 1;

        int p = query(node * 2, begin, mid, i, j);
        int q = query(node * 2 + 1, mid + 1, end, i, j);

        return marge(p, q);
    }
};


void solve(int cs)
{
    int q;

    cin >> n >> q;

    FOR(i, 1, n) cin >> a[i];

    SegmentTree st;

    st.build(1, 1, n);

    cout << "Case " << cs << ":" << endl;

    while (q--)
    {
        int type, l, r, val;

        cin >> type;

        if(type == 1){
            cin >> l >> r >> val;

            st.update(1, 1, n, l, r, val);

            continue;
        }

        cin >> l >> r;

        cout << st.query(1, 1, n, l, r) << endl;
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
