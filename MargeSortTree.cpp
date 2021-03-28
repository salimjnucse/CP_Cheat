#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

int const MXN = 2e5 + 10;

ll n, a[MXN];
vector<int>sgtree[4 * MXN];

struct SegmentTree
{
    int marge(int lftval, int rightval)
    {
        return lftval + rightval;
    }

    void build(int node, int begin, int end)
    {
        if(begin == end){
            sgtree[node].push_back(a[begin]);

            return;
        }
        int mid = (begin + end) >> 1;

        build(node * 2, begin, mid);

        build(node * 2 + 1, mid + 1, end);
    
        merge(sgtree[node * 2].begin(), sgtree[node * 2].end(), 
        sgtree[node * 2 + 1].begin(), sgtree[node * 2 + 1].end(), back_inserter(sgtree[node]));
    }
    
    // for update use ordered set instade of vector

    /* void update(int node, int begin, int end, int idx)
    {
        if(begin == end){
            if(begin == idx){
                data d;

                if(s[begin - 1] == 'A'){
                    s[begin - 1] = 'B';

                    d.cntb = 1;
                }
                else{
                    s[begin - 1] = 'A';

                    d.cnta = 1;
                }

                sgtree[node] = d;
            }

            return;
        }

        if(idx < begin || idx > end) return;

        int mid = (begin + end) >> 1;

        update(node * 2, begin, mid, idx);

        update(node * 2 + 1, mid + 1, end, idx);

        sgtree[node] = marge(sgtree[node * 2], sgtree[node * 2 + 1]);
    } */

    int query(int node, int begin, int end, int i, int j, int a, int b)
    {
        if(begin > j || end < i){
            return 0;
        }

        if(begin >= i && end <= j){
            return ((upper_bound(sgtree[node].begin(), sgtree[node].end(), b) - sgtree[node].begin()) 
            - (lower_bound(sgtree[node].begin(), sgtree[node].end(), a) - sgtree[node].begin()));
        }

        int mid = (begin + end) >> 1;

        int p = query(node * 2, begin, mid, i, j, a, b);
        int q = query(node * 2 + 1, mid + 1, end, i, j, a, b);

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
        int type, x, y, a, b;

        cin >> type;

        if(type == 1){
            cin >> x;

            //st.update(1, 1, n, x);

            continue;
        }

        cin >> x >> y >> a >> b;

        cout << st.query(1, 1, n, x, y, a, b) << endl;
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
