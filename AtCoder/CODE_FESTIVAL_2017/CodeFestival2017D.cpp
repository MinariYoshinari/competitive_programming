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

int n;
vector< pair<ll, Pll> > v;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ll h,p,max_h;
    rep(n){
        cin >> h >> p;
        max_h = max(max_h, h);
        v.emplace_back(h+p, Pll(h, p));
    }
    sort(all(v));
    
    vector< vector<ll> > dp(n+1, vector<ll>(n+1, 10LL*(ll)INF));
    dp[0][0] = 0;
    dp[0][1] = v[0].second.second;
    repp(i, n){
        repp(j, i+1){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(dp[i][j] <= v[i].second.first)
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + v[i].second.second);      
        }
    }
    
    int ans = n;
    while(dp[n][ans] == 10LL*(ll)INF) ans--;
    cout << ans << endl;
    return 0;
}