#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define md 1000000007

int const MXN = 1e5 + 5;

ll n, a[MXN], b[MXN], m, k;
ll starting_time[MXN], ending_time[MXN], low[MXN], depth[MXN];
bool visit[MXN];
vector<ll>graph[MXN], ans[MXN];

struct DFS{

    void dfs_tree(ll u, ll p, ll d)
    {
        visit[u] = true;
        depth[u] = d;
        low[u] = d;

        for(auto v : graph[u]){
            if(v == p) continue;

            if(!visit[v]){
                dfs_tree(v, u, d+1);

                low[u] = min(low[u], low[v]);
            }
            else{
                if(depth[v] < depth[u])
                    low[u] = min(low[u], depth[v]);
            }

            if(low[v] > depth[u]){
                cout << u << " and " << v << " are Bridge" << endl;
            }
        }
    }
};

void solve(int cs)
{
    cin >> n >> m;

    ll u, v;
    DFS dfs;
    memset(visit, false, sizeof visit);

    for(int i = 0; i < m; i++){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs.dfs_tree(0, -1, 0);

    for(int i = 0; i < n; i++){
        cout << i <<  " " << low[i] << " " << depth[i] << endl;
    }

    return;
}

int main()
{
    int t = 1, cs =  1;

//    cin >> t;

    while(t--) solve(cs++);
}


