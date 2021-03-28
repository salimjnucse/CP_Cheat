#include<bits/stdc++.h>
using namespace std;

#define ll long long

int const MXN = 1e4;

void Preprocess(){
    pwbase[0][0] = pwbase[1][0] = 1;
    for(ll i = 0; i < 2; i++){
        for(ll j = 1; j < MAX; j++){
            pwbase[i][j] = (pwbase[i][j - 1] * bases[i]) % mods[i];
        }
    }
}

struct Hashing{
    ll hsh[2][MAX];
    string str;

    Hashing(){}
    Hashing(string _str) {str = _str; memset(hsh, 0, sizeof(hsh)); build();}

    void Build(){
        for(ll i = str.size() - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                hsh[j][i] = (hsh[j][i + 1] * bases[j] + str[i]) % mods[j];
                hsh[j][i] = (hsh[j][i] + mods[j]) % mods[j];
            }
        }
    }

    pair<ll,ll> GetHash(ll i, ll j){
        assert(i <= j);
        ll tmp1 = (hsh[0][i] - (hsh[0][j + 1] * pwbase[0][j - i + 1]) % mods[0]) % mods[0];
        ll tmp2 = (hsh[1][i] - (hsh[1][j + 1] * pwbase[1][j - i + 1]) % mods[1]) % mods[1];
        if(tmp1 < 0) tmp1 += mods[0];
        if(tmp2 < 0) tmp2 += mods[1];
        return make_pair(tmp1, tmp2);
    }
};

struct Hashing{
    ll mod1 = 1e9 + 7, mod2 = 1e9 + 9, base = 397;

    ll pb1[MXN], pb2[MXN], hash1[MXN], hash2[MXN];

    void initialize()
    {
        pb1[0] = pb2[0] = 1;

        for(int i = 1; i <= MXN; i++)
        {
            pb1[i] = (pb1[i-1] * base) % mod1;
            pb2[i] = (pb2[i-1] * base) % mod2;
        }
    }
    void build_hash(string s)
        {
            hash1[0] = hash2[0] = 0;

            for(int i = 1; i <= s.size(); i++)
            {
                hash1[i] = ((hash1[i-1] * base) % mod1 + (s[i-1] - 'a')) % mod1;
                hash2[i] = ((hash2[i-1] * base) % mod2 + (s[i-1] - 'a')) % mod2;
            }
        }

        pair<ll, ll> query(ll l, ll r)
        {
            ll val1 = (hash1[r] - (hash1[l-1]* pb1[r - l + 1]) + mod1) % mod1;

            ll val2 = (hash2[r] - (hash2[l-1] * pb2[r - l + 1]) + mod2) % mod2;

            return make_pair(val1, val2);
        }

};

void solve(int cs)
{
    int n;

    cin >> n;

    string s, ss;

    cin >> s >> ss;

    Hashing h1, h2;

    h1.initialize();
    h2.initialize();

    h1.build_hash(s);
    h2.build_hash(ss);

    int m;

    cin >> m;

    int l1, l2, r1, r2;

    while(m--){
        cin >> l1 >> r1 >> l2 >> r2;

        pair<ll, ll> p1, p2;

        p1 = h1.query(l1, r1);

        p2 = h2.query(l2, r2);

        if(p1 == p2){
            cout << "Match" << endl;
        }

        else cout << "Does not Match" << endl;
    }

    return;
}

int main()
{
    int t = 1, cs =  1;

    cin >> t;

    while(t--) solve(cs++);
}
