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
    int h,w;
    cin >> h >> w;
    ll costs[10][10];
    rep(10)repp(j,10) cin >> costs[i][j];
    rep(10)repp(j,10)repp(k,10) costs[j][k] = min(costs[j][k], costs[j][i]+costs[i][k]);

    ll ans = 0, tmp;
    rep(h)repp(j,w){
        cin >> tmp;
        if(tmp != -1 && tmp != 1){
            ans += costs[tmp][1];
        }
    }
    cout << ans << endl;

}