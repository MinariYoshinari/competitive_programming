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

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(n) cin >> a[i];
    rep(m) cin >> b[i];

    ll ans = LLONG_MIN, hide = LLONG_MIN;
    rep(n) repp(j, m){
        if(a[i] * b[j] > ans){
            ans = a[i] * b[j];
            hide = i;   
        }
    }
    ans = LLONG_MIN;
    rep(n){
        if(i == hide) continue;
        repp(j, m){
            if(a[i] * b[j] > ans){
                ans = a[i] * b[j];
            }
        }
    }
    cout << ans << endl;
}