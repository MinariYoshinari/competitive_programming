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
    ll n, m, ans = 0LL;
    cin >> n >> m;
    if(n > m) swap(n, m);

    if(n == 1){
        if(m == 1) ans = 1LL;
        else if(m == 2) ans = 0LL;
        else ans = m-2LL;
    }else if(n == 2){
        ans = 0LL;
    }else{
        ans = (n-2) * (m-2);
    }

    cout << ans << endl;
    return 0;
}
