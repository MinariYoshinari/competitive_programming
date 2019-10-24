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
#define MAX 1001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(n) cin >> a[i];

    int p = 1;
    ll ans = 0LL;
    rep(n){
        if(a[i] > p){
            int diff = (a[i] - 1) /  p;
            ans += diff;
            if(p > 1 && a[i] % p == 0) a[i]--;
            a[i] -= p*diff;
        }
        if(a[i] == p) p++;
    }
    cout << ans << endl;
    return 0;
}