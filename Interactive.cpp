#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
int const MXN = 2000005;
#define MOD 998244353

ll query(ll a,ll b,ll c)
{
	cout <<"? "<< a <<" "<< b <<" "<< c <<endl;

	fflush(stdout);
	
    ll response;
	cin >> response;
	return response;
}


void solve(int cs)
{

	ll n;
	cin >> n;

	ll x = query(1,2,3);
	ll a,b,c,xx;
	ll im = -1,cr = -1;

	FOR(i, 2, n - 2){
		ll response = query(i, i + 1, i + 2);
		if(response != x){
			if(response == 0){
				im = i + 2;
				cr = i - 1;
			}
			else{
				cr = i + 2;
				im = i - 1;
			}
			break;
			
		}

		
	}

	VI v;

	v.push_back(im);

	for(int i = 1;i<=n;i++){
		if(i != cr && i != im){
			x = query(cr,im,i);
			if(x == 0) v.push_back(i);
		}  
	}

	cout <<"! "<<v.size()<<" ";
	for(int i = 0;i<v.size();i++) cout << v[i]<<" ";
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
