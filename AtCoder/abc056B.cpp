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
	ll N, K;
	cin >> N >> K;
	vector<ll> a(N);
	rep(N) cin >> a[i];
	sort(rall(a));
	vector< vector<bool> > dp(N, vector<bool>(K, false));
	
	ll low = 0, high = N-1;
	ll mid = -1;
	while(mid != (low+high)/2){
	    vector< vector<bool> > dp(N, vector<bool>(K, false));
	
	    mid = (low+high) / 2;
	    ll ii;
	    if(mid != 0){
    	    dp[0][a[0]] = true;
    	    ii = 1;
    	 }else{
    	    dp[0][a[1]] = true;
    	    ii = 2;
    	 }
    	 
	    reppp(i, 1, N-1){
	        if(ii == mid){
	            ii++;
	            continue;
	        }
		    dp[i][a[ii]] = true;
		    repp(j, K){
			    if(dp[i-1][j] || dp[i-2][j]){
			        if(j + a[ii] < K){
				        dp[i][j+a[ii]] = true;
				    }
				    dp[i][j] = true;
			    }
		    }
		    ii++;
	    }
	}
	rep(N){
		repp(j, K) cout << dp[i][j] << " ";
		cout << endl;
	}
}

