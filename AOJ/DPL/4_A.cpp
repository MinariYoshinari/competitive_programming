#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cassert>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<bitset>

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
    int n; ll v, ans = 0;
    cin >> n >> v;

    ll a[4][n];
    rep(4) repp(j, n) cin >> a[i][j];
    vector<ll> vec;
    rep(n){
        repp(j, n){
            vec.push_back(a[0][i]+a[1][j]);
        }
    }

    sort(all(vec));

    rep(n){
        repp(j, n){
            ll x = v-a[2][i]-a[3][j];
            ans += (ll)(upper_bound(all(vec), x) - lower_bound(all(vec), x));
        }
    }

    cout << ans << endl;

}
