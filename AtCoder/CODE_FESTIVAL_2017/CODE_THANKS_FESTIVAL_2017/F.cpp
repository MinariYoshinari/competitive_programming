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

ll productmod(ll x, ll y){
  if(x*y >= MOD) return (x*y) % MOD;
  else return x*y;
}

ll powmod(ll a, ll t){
    ll ret = 1;
    while(t){
        if(t & 1){
            ret = productmod(ret, a);
        }
        a = productmod(a, a);
        t >>= 1;
    }
    return ret;
}

signed main(){
    int n,k,a, s = 0;
    cin >> n >> k;
    
    map<int, ll> mp;
    rep(n){
        cin >> a;
        mp[a]++;
        s += a;
    }

    int i = 0;
    ll dp[2][2*s];
    fill(dp[0], dp[2], 0LL);
    dp[1][0] = 1;
    for(auto itr=mp.begin();itr!=mp.end();itr++){
       ll p = powmod(2, (itr->second)-1);
       repp(j, 2*s){
           if(dp[1-i][j] == 0) continue;
           (dp[i][j] += (p * dp[1-i][j]) % MOD) %= MOD;
           (dp[i][j^(itr->first)] += (p * dp[1-i][j]) % MOD) %= MOD;
           dp[1-i][j] = 0;
        }
        i = 1 - i;
    }

    cout << dp[1-i][k] << endl;

}