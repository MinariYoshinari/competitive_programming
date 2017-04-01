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
#define MAX 100000
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

vector<ll> es[MAX+1];
ll dp[MAX+1][10+1];
vector<ll> v(MAX+1), d(MAX+1), c(MAX+1);

void bfs(ll vv, ll depth, ll c){
	rep(depth+1){
		dp[vv][i] = c;
	}
	
	queue<P> que;
	for(ll to : es[vv]){
		if(dp[to][depth-1] == 0) que.push(P(to, depth-1));
	}
	while(!que.empty()){
		P p = que.front(); que.pop();
		rep(p.second+1){
			dp[p.first][i] = c;
		}
		if(p.second == 0) continue;
		for(ll to : es[p.first]){
			if(dp[to][p.second-1] == 0) que.push(P(to, p.second-1));
		}
	}
}


signed main(){
	ll N, M, Q;
	cin >> N >> M;
	fill(dp[0], dp[N+1], 0);
	rep(M){
		ll tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		es[tmp1].push_back(tmp2);
		es[tmp2].push_back(tmp1);
	}
	cin >> Q;
	rep(Q){
		cin >> v[i] >> d[i] >> c[i];
	}
	for(int i=Q-1;i>=0;i--){
		if(dp[v[i]][d[i]] == 0){
			bfs(v[i], d[i], c[i]);
			repp(j, d[i]){
				if(dp[v[i]][j] == 0) dp[v[i]][j] = dp[v[i]][d[i]];
			}
		}
	}
	
	rep(N){
		cout << dp[i+1][0] << endl;
	}
	
}

