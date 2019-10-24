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
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,a, mn = INF, mx = 0;
    cin >> n;
    map<int, vector<int> > mp;
    rep(n){
        cin >> a;
        if(a < mn) mn = a;
        if(a > mx) mx = a;
        mp[a-1].pb(i);
        mp[a].pb(i);
        mp[a+1].pb(i);
    }

    int ans = 0;
    reppp(i, mn, mx){
        ans = max(ans, (int)mp[i].size());
    }
    cout << ans;
}
