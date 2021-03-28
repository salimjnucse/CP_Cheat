#include<bits/stdc++.h>
using namespace std;
#define bug(a)       cerr << __LINE__ <<" Says " << #a << " : " << a << endl;
#define ll long long
#define plus(a,b) (a+b)
#define minus(a,b) (a-b)
#define mul(a,b) (a*b)
#define div(a,b) (a/b)
#define mod(a,b) (a%b)
#define sq(n)    (n*n)
const int MXN = 200005;
ll a[MXN], n, m;

void solve(int cs)
{
    cin>>n;

    if(n%2)n--;

    cout<<n/2<<endl;

}

int main()
{
    int t = 1, x = 1;

    cin>>t;

    while(t--) solve(x++);


    return 0;
}

