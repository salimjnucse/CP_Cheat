#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define md 1000000007

int const MXN = 1e5 + 5;

ll n, a[MXN], b[MXN], m, k;
ll starting_time[MXN], ending_time[MXN], low[MXN], depth[MXN], visit[MXN], component;
vector<ll>graph[MXN], ans[MXN];

struct DFS{

    void dfs_tree(ll u, ll p, ll d)
    {
        visit[u]++;
        if(visit[u] >= 2) ans[component].push_back(a[u]);

        for(auto v : graph[u]){
            if(visit[v] < 2){
                dfs_tree(v, u, d + 1);
            }
        }
    }
};

void solve(int cs)
{
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    cin >> m;

    ll u, v;
    DFS dfs;
    memset(visit, 0, sizeof visit);

    for(int i = 0; i < m; i++){
        cin >> u >> v;

        graph[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(visit[i]) continue;

        dfs.dfs_tree(i, -1, 0);
        component++;
    }

    ll tot_cost = 0, way = 1;

    for(int i = 1; i <= n; i++){
        if(visit[i] == 1) tot_cost += a[i];
    }

    for(int i = 0; i < component; i++){
        sort(ans[i].begin(), ans[i].end());

        ll now = 0, cnt = 0;
        if(ans[i].size())now = ans[i][0];

        tot_cost += now;
        for(int j = 0; j < ans[i].size(); j++){
//            cout << ans[i][j] <<" ";

            if(ans[i][j] == now) cnt++;
        }

//        cout << cnt << endl;

        if(cnt)way *= cnt;

        way %= md;

//        cout << endl;
    }

    if(way == 1){
        tot_cost = 0;

        for(int i = 1; i <= n; i++) tot_cost += a[i];
    }

    cout << tot_cost << " " << way << endl;

    return;
}

int main()
{
    int t = 1, cs =  1;

//    cin >> t;

    while(t--) solve(cs++);
}

