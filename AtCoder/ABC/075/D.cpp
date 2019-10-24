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
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    rep(n) cin >> x[i] >> y[i];

    ll ans = LLONG_MAX;
    rep(n-1){
        reppp(ii, i+1, n-1){
            ll xmin = min(x[i], x[ii]), xmax = max(x[i], x[ii]);
            repp(j, n-1){
                reppp(jj, j+1, n-1){
                    ll ymin = min(y[j], y[jj]), ymax = max(y[j], y[jj]);
                    int cnt = 0;
                    repp(k, n){
                        if(xmin <= x[k] && x[k] <= xmax && ymin <= y[k] && y[k] <= ymax) cnt++;
                    }
                    if(cnt >= m) ans = min(ans, (ymax-ymin)*(xmax-xmin));
                }
            }
        }
    }

    cout << ans << endl;
}