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

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, min_b = INT_MAX;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(n){
        cin >> a[i] >> b[i];
        if(a[i] > b[i]){
            if(b[i] < min_b){
                min_b = b[i];
            }
        }
    }

    if(min_b == INT_MAX){
        cout << 0 << endl;
        return 0;
    }
    ll ans = accumulate(all(a), 0LL) - min_b;
    cout << ans << endl;
    return 0;
}
