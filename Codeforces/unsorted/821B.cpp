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
    double m, b;
    cin >> m >> b;

    ll x = 0; // x+y
    ll ans = 0;
    while(b-(double)x / m + EPS > 0){
        ll y = (ll)(b - (double)x / m + EPS);
        ll tmp = (x+1) * (y+1) * (x+y) / 2;
        //ll tmp = (ll)(x*(x+1)/2*(y+1) + y*(y+1)/2*(x+1));
        /*
        repp(j, (int)y+1){
            repp(k, (int)x+1){
                tmp += j + k;
            }
        }
        */
        if(tmp > ans) ans = tmp;
        x += 1;
    }
    cout << ans;
}