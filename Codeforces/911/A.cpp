#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
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
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(n) cin >> v[i];
    ll m = *min_element(all(v));
    ll a = -1LL, b = -1LL;
    ll ans = n;
    rep(n){
        if(v[i] == m){
            if(a != -1LL) b = a;
            a = i;
            if(b != -1LL) ans = min(ans, a-b);
        }
    }
    cout << ans << endl;

}
