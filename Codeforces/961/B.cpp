#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), t(n);
    rep(n) cin >> a[i];
    rep(n) cin >> t[i];

    vector<ll> atk(n-k+1, 0LL);
    rep(k){
        atk[0] += (1LL-t[i])*a[i];
    }
    reppp(i, 1, n-k+1){
        atk[i] = atk[i-1] - (1LL-t[i-1])*a[i-1] + (1LL-t[i+k-1])*a[i+k-1];
    }
    ll ans = *max_element(all(atk));
    rep(n) ans += t[i] * a[i];
    cout << ans << endl;
}
