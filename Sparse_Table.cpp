/// Sparse table. Solves static RMQ problem (without element changes).
/// O(NlogN) on precalculation, O(1) on query.

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forf(i, a, b)  for(int i = a; i <= b; i++)
#define forb(i, a, b)  for(int i = b; i >= a; i--)

int const MXN = 1e5 + 5;

ll n, a[MXN];

ll spt[MXN][20], lg[MXN];

struct Sparse_Table
{

    void initialize(){
        lg[1] = 0;

        forf(i, 2, n){
    		lg[i] = lg[i / 2] + 1;
        }
    }

    void build_sparse_table(){
        initialize();
        /// max value sparse table
        /// it also used for  range MAX, MIN, OR, AND, GCD, LCM
        /// must change query
        forf(j, 0, lg[n]){
            forf(i, 1, n - (1 << j)  + 1){
                if(j == 0) spt[i][j] = a[i];
                else{
                    spt[i][j] = min(spt[i][j - 1], spt[i + (1 <<(j - 1))][j - 1]);
                }
            }
        }
    }

    ll query(int l, int r){
        int len = r - l + 1;
        int k = lg[len];
        return min(spt[l][k], spt[r - (1 << k) + 1][k]);
    }
};


void solve(int cs)
{
    cin >> n;

    forf(i, 1, n) cin >> a[i];

    Sparse_Table sp;

    sp.build_sparse_table();

    int q;

    cin >> q;

    while (q--)
    {
        int l, r;

        cin >> l >> r;

        cout << sp.query(l + 1, r + 1) << endl;
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
