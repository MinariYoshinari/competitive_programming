#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    // ios::sync_with_stdio(0); cin.tie(0);
    int n; ll x;
    cin >> n >> x;

    vector<ll> t(n+1);
    rep(n){
        cin >> t[i+1];
    }
    t[0] = t[1] - x;
    
    vector< vector<ll> > dp(n+1, vector<ll>(n+1, 0));
    repp(i, n+1){
        repp(k, n){
            int j = (int)(lower_bound(all(t), t[i]+x) - t.begin());
            if(j <= n) dp[j][k+1] = max(dp[j][k+1], dp[i][k] + min(t[j]-t[i], x));
            j--;
            if(j <= n) dp[j][k+1] = max(dp[j][k+1], dp[i][k] + min(t[j]-t[i], x));
        }
    }

    reppp(k, 1, n){
        ll ans = 0;
        reppp(i, 1, n) ans = max(ans, dp[i][k]);
        cout << ans << endl;
    }

}
