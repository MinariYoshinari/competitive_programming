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

signed main(){
	ll N, W;
	cin >> N >> W;
	ll w[N], v[N];
	rep(N){
		cin >> w[i] >> v[i];
	}
	ll dp[N+1][W+1];
	fill(dp[0][0], dp[1][0], 0);
	reppp(i, 1, N){
		repp(j, W+1){
			if(dp[i-1][j] + w[i-1] <= W){
				dp[i][j] = dp[i-1][j] + w[i-1];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[N][W];
}

