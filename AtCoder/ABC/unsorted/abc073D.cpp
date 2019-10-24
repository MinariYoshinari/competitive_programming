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
#define MAX 40000
#define INF 2147483647
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};


signed main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, a, b, rtmp, r;
    vector<int> rv, av, bv;
    ll c;
    vector<ll> cv;
    cin >> n >> m >> r;
    rep(r){
        cin >> rtmp;
        rv.pb(rtmp-1);
    }
    sort(all(rv));
    vector< vector<ll> > d(n, vector<ll>(n, MOD));
    rep(n) d[i][i] = 0;
    rep(m){
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    repp(i, n){
        repp(j, n){
            repp(k, n){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    ll ans = MOD, tmp;
    do{
        tmp = 0;
        repp(i, r-1){
            tmp += d[rv[i]][rv[i+1]];
        }
        ans = min(ans, tmp);
    }while( next_permutation(all(rv)) );
    cout << ans << endl;
}