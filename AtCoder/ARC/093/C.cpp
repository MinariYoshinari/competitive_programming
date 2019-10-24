#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    ll a[n+2], d[n], total = 0LL;
    a[0] = 0LL;
    rep(n) cin >> a[i+1];
    a[n+1] = 0LL;
    rep(n+1){
        d[i] = abs(a[i+1] - a[i]);
        total += d[i];
    }
    a[0] = 0LL;
    reppp(i, 1, n+1){
        cout << total - d[i-1] - d[i] + abs(a[i+1] - a[i-1]) << endl;
    }
}
