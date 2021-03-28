#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const MXN = 5e4;

struct KMP_Patern_Match
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

    bool patern_matcher(string s, string ss)
    {
        int n = s.size(), m = ss.size();

        vector<int> pi(m);

        pi = build_pi_table(ss, m);

        int j = 0;

        for(int i = 0; i < n; i++){
            while (j > 0 && ss[j] != s[i]) j = pi[j - 1];

            if(s[i] == ss[j]) j++;
            
            if(j == m) return true;
        }

        return false;
    }
};

void solve(int cs)
{
    string s, ss;

    cin >> s;

    int q;

    cin >> q;

    while (q--)
    {
         cin >> ss;

        KMP_Patern_Match kmp;

        bool flag = kmp.patern_matcher(s, ss);

        cout << (flag ? "y" : "n") << endl;
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
