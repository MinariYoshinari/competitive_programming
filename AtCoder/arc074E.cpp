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

signed main(){
	int N, M;
	cin >> N >> M;
	vector< pair<int, int> > conds[N+1];
	rep(M){
		int l, r, x;
		cin >> l >> r >> x;
		conds[r].emplace_back(l, x);
	}

	vector< vector< vector<int> > > dp(N+1, vector< vector<int> >(N+1, vector<int>(N+1, 0)));

	dp[0][0][0] = 1;
	rep(N){
		repp(j, N){
			repp(k, N){
				int r = max(i, max(j, k));
				int add = dp[i][j][k];
				dp[r+1][j][k] += add;
				if(dp[r+1][j][k] > MOD) dp[r+1][j][k] -= MOD;
				dp[i][r+1][k] += add;
				if(dp[i][r+1][k] > MOD) dp[i][r+1][k] -= MOD;
				dp[i][j][r+1] += add;
				if(dp[i][j][r+1] > MOD) dp[i][j][r+1] -= MOD;

				for(auto p : conds[r+1]){
					int l = p.first, x = p.second;
					int ii = 0, jj = 0, kk = 0;
					if(l <= i) ii = 1;
					if(l <= j) jj = 1;
					if(l <= k) kk = 1;
					if(jj + kk + 1 != x) dp[r+1][j][k] = 0;
					if(ii + kk + 1 != x) dp[i][r+1][k] = 0;
					if(ii + jj + 1 != x) dp[i][j][r+1] = 0;
				}
			}
		}
	}

	ll ans = 0;
	repp(i, N){
		repp(j, N){
			if((i > 0 && i == j)) continue;
			ans += dp[i][j][N];
			if(ans > MOD) ans -= MOD;
			ans += dp[i][N][j];
			if(ans > MOD) ans -= MOD;
			ans += dp[N][i][j];
			if(ans > MOD) ans -= MOD;
		}
	}
	cout << ans % MOD << endl;
	return 0;
}

