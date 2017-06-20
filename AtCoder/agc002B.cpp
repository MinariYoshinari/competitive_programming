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
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

ll func(ll a, ll b){
	ll ret = 0;
	if(a > b) swap(a,b);
	while(a > 0){
		ret += 2 * a * (b/a);
		ll c = b % a;
		b = a;
		a = c;
	}
	return ret-b;
}

signed main(){
	ll N, X;
	cin >> N >> X;

	cout << N + func(X, N-X);
}

