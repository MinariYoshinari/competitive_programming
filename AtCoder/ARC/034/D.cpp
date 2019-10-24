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

ll f(ll x){
    ll ret = 0;
    while(x){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> ans;
    for(ll i=n-153;i<=n;i++){
        if(i + f(i) == n){
            ans.push_back(i);
        }
    }
    cout << (int)ans.size() << endl;
    for(ll x: ans){
        cout << x << endl;
    }
}
