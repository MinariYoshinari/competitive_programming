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
#define MOD 1000000007LL
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
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;

    vector<ll> dp(n-1, 0LL), sum(n-1, 0LL);
    dp[0] = 0; dp[1] = 1; 
    sum[0] = 0; sum[1] = 1;
    reppp(i, 2, n-2){
        if(i < k) dp[i] = (dp[i-1] * 2) % MOD;
        else dp[i] = (sum[i-1] - sum[max(0, i-k-1)] + MOD) % MOD;
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }
    cout << (sum[n-2] - sum[max(0, n-k-1)] + MOD) % MOD << endl;
}