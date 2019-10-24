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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
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
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a[0];
    rep(n-1){
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    if(n == 2){
        cout << abs(2*a[0] - a[1]);
        return 0;
    }
    ll tmp, ans  = abs(2*a[0] - a[n-1]);
    reppp(i, 1, n-2){
        tmp = abs(2*a[i] - a[n-1]);
        if(tmp < ans) ans = tmp;
    }
    cout << ans;
    return 0;
}
