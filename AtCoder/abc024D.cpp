#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007LL
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	ll a, b, c;
	cin >> a >>  b >> c;
	a %= MOD;
	b %= MOD;
	c %= MOD;
	ll ab = (a*b) % MOD;
	ll bc = (b*c) % MOD;
	ll ca = (c*a) % MOD;
	ll cc = ((bc-ab)%MOD)/((ca-bc+ab)%MOD);
	ll rr = (bc-ca)/(ab-bc+ca);
	cout << rr % MOD << " " << cc % MOD << endl;
}

