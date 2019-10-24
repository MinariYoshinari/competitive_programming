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

bool compare( const Pll& left, const Pll& right ) {
    return (left.first - left.second) > (right.first - right.second);
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);

    int x,y,z;
    cin >> x >> y >> z;
    int n = x+y+z;
    vector<Pll> ab(n);
    ll csum = 0LL;
    rep(n){
        ll a,b,c;
        cin >> a >> b >> c;
        ab[i].first = a-c;
        ab[i].second = b-c;
        csum += c;
    }
    sort(all(ab), compare);

    // aの最大化
    vector<ll> a(n, 0LL);
    priority_queue<ll, vector<ll>, greater<ll> > que;
    rep(x){
        que.push(ab[i].first);
        a[x] += ab[i].first;
    }
    reppp(k, x+1, x+z+1){
        que.push(ab[k-1].first);
        a[k] = a[k-1] + ab[k-1].first  - que.top();
        que.pop();
    }

    // bの最大化
    vector<ll> b(n, 0LL);
    que = decltype(que)();
    rep(y){
        que.push(ab[n-1-i].second);
        b[x+z] += ab[n-1-i].second;
    }
    for(int k=x+z-1;k>=x;k--){
        que.push(ab[k].second);
        b[k] = b[k+1] + ab[k].second - que.top();
        que.pop();
    }

    ll ans = LLONG_MIN;
    reppp(k, x, x+z+1){
        ans = max(ans, a[k]+b[k]);
    }
    cout << ans+csum << endl;
}
