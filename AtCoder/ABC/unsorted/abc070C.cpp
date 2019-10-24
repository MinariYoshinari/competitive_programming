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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

signed main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(n) cin >> a[i];
    sort(all(a));
    if(a.back() == 10e18){
        cout << 10e18;
        return 0;
    }
    ll ans = a[0];
    reppp(i, 1, n-1){
        if(ans % a[i] == 0) continue;
        if(a[i] % ans == 0) ans = a[i];
        else ans = ans / gcd(ans, a[i]) * a[i];
        if(ans == 10e18) break;
    }
    cout << ans;
    return 0;
}

