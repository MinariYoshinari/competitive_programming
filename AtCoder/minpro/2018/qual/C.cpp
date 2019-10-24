#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int n;
ll dp[18][262144], x[18], csum[262144], vsum[262144];
ll memo[262144][18][2];

ll rec(int s, int i, int takahashi){
    if(s == 0) return 0LL;
    if(memo[s][i][takahashi] != -1) return memo[s][i][takahashi];

    if(takahashi){
        ll ret = max(rec(s, i+1, 0), dp[i][s]);
        memo[s][i][1] = ret;
        return ret;
    }else{
        ll ret = LLONG_MAX;
        repp(j, n){
            if(((s >> j) & 1)) ert = min(ret, rec(s ^ (1 << j), i, 1));
        }
        memo[s][i][0] = ret;
        return ret;
    }
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(n) cin >> x[i];
    rep(n-1) x[i+1] += x[i];
    rep(n) cin >> csum[1<<i];
    rep(n) cin >> vsum[1<<i];

    int m = pow(2, n);
    repp(s, m){
        repp(i, n){
            memo[s][i][0] = -1;
            memo[s][i][1] = -1;
            if((s >> i) & 1) continue;
            if(!dp[i][s|(1<<i)]){
                csum[s|(1<<i)] = csum[s] + csum[1<<i];
                vsum[s|(1<<i)] = vsum[s] + vsum[1<<i];
            }
            repp(j, n){
                if(x[j] >= csum[s|(1<<i)]) dp[j][s|(1<<i)] = vsum[s|(1<<i)];
                dp[j][s|(1<<i)] = max(dp[j][s|(1<<i)], dp[j][s]);
            }
        }
    }

    cout << rec(m-1, 0, 0) << endl;
}
