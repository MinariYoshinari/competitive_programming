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

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(ll j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};


signed main(){
    ll n;
    cin >> n;
    bool flag = false;
    vector<ll> a(n);
    rep(n){
        cin >> a[i];
        if(a[i] >= n) flag = true;
    }
    if(!flag){
        cout << 0;
        return 0;
    }
    
    flag = true;
    ll ans = 0LL;
    vector<ll> b(n);
    while(flag){
        rep(n) b[i] = a[i] / n;
        ll tmp = accumulate(all(b), 0LL);
        ans += tmp;
        flag = false;
        rep(n){
            b[i] = tmp - b[i] + a[i] % n;
            if(b[i] >= n) flag = true;
        }
        swap(a, b);
    }

    cout << ans;
    return 0;
}