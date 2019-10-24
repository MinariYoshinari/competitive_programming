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
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    vector<ll> a(7);
    rep(7) cin >> a[i];
    ll ans = a[1], tmp = a[1];
    int v [3] = {0, 3, 4};
    rep(3){
        if(a[v[i]] >= 2) ans += a[v[i]] / 2 * 2;
    }
    if(a[0] == 1 && a[3] == 1 && a[4] == 1) ans += 3;

    if(a[0] > 0 && a[3] > 0 && a[4] > 0) tmp += 3;
    rep(3){
        a[v[i]]--;
        if(a[v[i]] >= 2) tmp += a[v[i]] / 2 * 2;
    }
    cout << max(ans, tmp);
}