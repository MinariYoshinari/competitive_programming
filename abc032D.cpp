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
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	ll N, W;
	cin >> N >> W;
	vector<ll> v(N), w(N);
	ll sum_v = 0;
	rep(N){
	    cin >> v[i] >> w[i];
	    sum_v += v[i];
	}
	vector< vector<ll> > dp(N, vector<ll>((W > 1000 ? sum_v : W)+1, 0));
	
	if(W > 1000){
	    dp[0][v[0]] = w[0];
	}else{
	    dp[0][w[0]] = v[0];
	}
	reppp(i, 1, N){
	    ll vv = v[i], ww = w[i];
	    
	    if(W > 1000){
	        swap(vv, ww);
	    }else{
	        repp(j, W+1){
	            if(j < ww){
	                dp[i][j] = dp[i-1][j];
	            }else{
	                dp[i][j] = max(dp[i-1][j], dp[i-1][j-ww] + vv);
	            }
	        }
	    }
	}
	
	
	repp(j, dp[N-1].size()){
	    cout << dp[N-1][j] << endl;
	}
}
