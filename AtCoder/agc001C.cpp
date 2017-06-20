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
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

ll N, K;

ll walk_even(ll node, vector<ll> es[], ll depth, vector<bool> use){
	use[node] = true;
	ll ret = 0;
	for(ll next : es[node]){
		if(!use[next]) ret += walk_even(next, es, depth+1, use);
	}
	if(depth > K) ret++;
	return ret;
}


signed main(){
	cin >> N >> K;
	vector<P> es_odd;
	vector<ll> es_even[N];
	rep(N-1){
		ll from, to;
		cin >> from >> to;
		from--; to--;
		es_odd.push_back(P(from, to));
		es_even[from].push_back(to);
		es_even[to].push_back(from);
	}

	vector<ll> ans;
	if(K % 2 == 0){
		K /= 2;
		rep(N){
			ans.push_back(walk_even(i, es_even, 0, vector<bool>(N, false)));
		}
	}else{
		K = (K-1)/2;
		for(P e : es_odd){
			vector<bool> use(N, false);
			use[e.second] = true;
			ll tmp1 = walk_even(e.first, es_even, 0, use);
			use[e.second] = false; use[e.first] = true;
			ll tmp2 = walk_even(e.second, es_even, 0, use);
			//cout << tmp1 << " " << tmp2 << endl;
			ans.push_back(tmp1 + tmp2);
		}
	}
	cout << *min_element(all(ans));
}

