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
#define MAX 2000000001
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
    int n;
    cin >> n;
    vector< vector<ll> > a(n, vector<ll>(n));
    rep(n) repp(j, n) cin >> a[i][j];

    ll ans = 0LL;
    rep(n){
        reppp(j, i+1, n-1){
            ll min_distance = MAX;
            int min_k = -1;
            repp(k, n){
                if(k == i || k == j) continue;
                if(min_distance > a[k][i]+a[k][j]){
                    min_distance = a[k][i]+a[k][j];
                    min_k = k;
                }

            }
            if(min_distance < a[i][j]){
                cout << -1;
                return 0;
            }else if(min_distance > a[i][j]){
                ans += a[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}
