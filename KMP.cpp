#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
int const MXN = 5e4;

struct KMP
{
    vector<int> build_pi_table(string s, ll n)
    {
        vector<int> pi(n);
        pi[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];

            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];

            if (s[i] == s[j])
                j++;

            pi[i] = j;
 
        }

        return pi;
    }
};

void solve(int cs)
{
    string s;

    cin >> s;

    ll n = s.size();

    KMP kmp;

    vector<int>pi(n);

    pi = kmp.build_pi_table(s, n);

    for (int i = 0; i < n; i++)
        cout << pi[i] << " ";

    cout << endl;

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
