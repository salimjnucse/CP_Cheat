#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

int const MXN = 2e5 + 5;

ll n, a[MXN], parent[MXN][22], depth[MXN];

vector<ll> graph[MXN];

struct LCA
{
    bool checkbit(int mask, int k)
    {
        return mask & (1 << k);
    }

    void dfs(int u, int p, int d)
    {
        parent[u][0] = p;
        depth[u] = d;

        for(auto v: graph[u]){
            if(v == p) continue;

            dfs(v, u, d + 1);
        }
    }

    void sparse_table()
    {
        FOR(k, 1, 20){
            FOR(u, 1, n){
                int first_parent = parent[u][k - 1];

                if(first_parent == -1) parent[u][k] = -1;
                else{
                    parent[u][k] = parent[first_parent][k - 1];
                }
            }
        }
    }

    ll Kth_parent(int u, int k)
    {
        FOR(i, 0, 20){
            if(checkbit(k, i)){
                u = parent[u][i];
            }
        }
        return u;
    }

    ll lca(int root, int u, int v)
    {
        memset(parent, -1, sizeof parent);
        
        dfs(root, -1, 0);
        sparse_table();

        if(depth[u] > depth[v]){
            u = Kth_parent(u, depth[u] - depth[v]);
        }
        else if(depth[u] < depth[v]){
            v = Kth_parent(v, depth[v] - depth[u]);
        }

        cout << u << " " << v << endl;

        if(u == v) return u;

        ll lo = 0, hi = depth[u], ans;

        while (lo < hi)
        {
            ll mid = (lo + hi) >> 1;

            int p = Kth_parent(u, mid);
            int q = Kth_parent(v, mid);

            // cout << p << " " << q << endl;

            if(p == q){
                hi = mid;
                ans = p;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};


void solve(int cs)
{
    cin >> n;

    int u, v;

    FOR(i, 0, n - 2){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    LCA lc;

    int q;

    cin >> q;

    while (q--)
    {
        cin >> u >> v;

        int ans = lc.lca(1, u, v);

        cout << ans << endl;
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
