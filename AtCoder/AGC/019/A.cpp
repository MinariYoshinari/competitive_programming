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
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
#define Pdd pair<double, double>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    vector< Pdd > v;
    double n, tmp, second = 0.25;
    rep(4){
        cin >> tmp;
        v.pb(Pdd(tmp * (2.0/second), second));
        second *= 2;
    }
    cin >> n;

    sort(all(v));
    ll ans = 0;
    rep(4){
        Pdd p = v[i];
        //cout << p.first << " " << p.second << endl;
        double price = p.first * (p.second/2.0);
        ll tmp = n / p.second;
        n -= (double)tmp * p.second;
        ans += (ll)price * tmp;
        if(n == 0) break;
    }
    cout << ans;
}
