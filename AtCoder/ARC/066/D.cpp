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
#include<bitset>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 100001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;

ll addmod(ll x, ll y){
  if(x+y >= MOD) return x+y-MOD;
  else return x+y;
}

ll productmod(ll x, ll y){
  if(x*y >= MOD) return (x*y) % MOD;
  else return x*y;
}

signed main(){
    unsigned long long  n;
    cin >> n;
    int digit = ceil(log2((double)n+0.1));
    bitset<64> nbs(n);
    ll dp[digit][3];
    fill(dp[0], dp[digit], 0);
    dp[digit-1][0] = 1;
    dp[digit-1][1] = 1;
    dp[digit-1][2] = 0;
    for(int i=digit-2;i>=0;i--){
        if(nbs.test(i)){
            dp[i][0] = dp[i+1][0];
            dp[i][1] = addmod(dp[i+1][0], dp[i+1][1]);
            dp[i][2] = addmod(productmod(dp[i+1][1], 2), productmod(dp[i+1][2], 3));
        }else{
            dp[i][0] = addmod(dp[i+1][0], dp[i+1][1]);
            dp[i][1] = dp[i+1][1] % MOD;
            dp[i][2] = addmod(dp[i+1][1], productmod(dp[i+1][2], 3));
        }
    }

    ll ans = 0;
    rep(3){
        ans = addmod(ans, dp[0][i]);
    }
    cout << ans << endl;
}
