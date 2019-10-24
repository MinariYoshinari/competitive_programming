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

const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n,k, ans = 0LL;
    cin >> n >> k;
    reppp(b, k+1, n+1){
        ans += n/b*(b-k) + max(((n-n/b*b)+1-k),0LL);
        // cerr << n/b*(b-k) << " " << ((n-n/b*b)+1-k) << endl;
    }

    cout << min(n*n, ans) << endl;
}
