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

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-12
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; ll K;
    cin >> N >> K;
    vector<ll> a(N),b(N), ans;
    rep(N) cin >> a[i] >> b[i];
    
    ll bb = 0;
    rep(N) if((a[i]|K) == K) bb += b[i];
    ans.pb(bb);

    ll dec = 2;
    while(dec <= K){
        ll kk = (K - dec)|(dec-1);
        bb = 0;
        rep(N) if((a[i]|kk) == kk) bb += b[i];
        ans.pb(bb);
        dec *= 2;
    }

    cout << *max_element(all(ans)) << endl;
}
