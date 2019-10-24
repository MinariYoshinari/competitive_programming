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
#include<numeric>

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
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int n,m;
    cin  >> n >> m;
    vector<int> a(n), b(m);
    rep(n) cin >> a[i];
    rep(m) cin >> b[i];

    vector< vector<int> > dp(n+1, vector<int>(m+1, 0)), sum(n+1, vector<int>(m+1, 0));

    dp[n-1][m] = a[n-1];
    sum[n-1][m] = a[n-1];
    for(int i=n-2;i>=0;i--){
        dp[i][m] = dp[i+2][m] + a[i];
        sum[i][m] = sum[i+1][m] + a[i];
    }

    dp[n][m-1] = b[m-1];
    sum[n][m-1] = b[m-1];
    for(int j=m-2;j>=0;j--){
        dp[n][j] = dp[n][j+2] + b[j];
        sum[n][j] = sum[n][j+1] + b[j];
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            sum[i][j] = sum[i][j+1] + b[j];
            dp[i][j] = sum[i][j] - min(dp[i+1][j], dp[i][j+1]);
        }
    }

    cout << dp[0][0] << endl;
}