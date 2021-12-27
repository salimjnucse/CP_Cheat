#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 10000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
int const MXN = 2e5 + 5;

///ababaxbababa

struct Z_algorithm{
    vector<int>build_Z_algo(string s){

        int left = 0, right = 0;
        int sz = s.size();
        vector<int>Z(sz + 5);

        for(int i = 1; i < sz; i++){
            if(i > right){
                left = right = i;
                
                while(right < sz && s[right] == s[right - left]) right++;

                Z[i] = right - left;
                right--;
            }
            else{
                int k = i - left;

                if(Z[k] < right - i + 1) Z[i] = Z[k];

                else{
                    left = i;

                    while(right < sz && s[right] == s[right - left]) right++;

                    Z[i] = right - left;
                    right--;
                }
            }
        }

        return Z;
    }
};

void solve(int cs)
{
    string s;

    cin >> s;

    Z_algorithm tmp;

    vector<int> z = tmp.build_Z_algo(s);

    for(int i = 0; i < s.size(); i++){
        cout << z[i] << "";
    }
    cout << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif
    int t = 1, cs = 1;
    cin >> t;

    while (t--){
       solve(cs);
    }
}
