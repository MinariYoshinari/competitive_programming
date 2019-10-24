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
#define reppp(i, m, n) for(ll i=m;i<=n;i++)
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

signed main(){
	ll H, W;
	cin >> H >> W;
	ll h = H/2, w = W/2, ans = 1e11;
	if(H % 3 == 0 || W % 3 == 0){
		cout << 0;
	}else{
	reppp(i, 1, W/2+1){
		vector<ll> p(3);
		p[0] = H * i;
		p[1] = h * (W-i);
		p[2] = (H-h) * (W-i);
		ll tmp = *max_element(all(p)) - *min_element(all(p));
		if(tmp < ans) ans = tmp;
	}
	reppp(i, 1, H/2+1){
		vector<ll> p(3);
		p[0] = W * i;
		p[1] = w * (H-i);
		p[2] = (W-w) * (H-i);
		ll tmp = *max_element(all(p)) - *min_element(all(p));
		if(tmp < ans) ans = tmp;
	}
	cout << min(ans, min(H, W));
	}
}

