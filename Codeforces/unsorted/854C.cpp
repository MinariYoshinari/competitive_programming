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
    int n, k;
    scanf("%d %d", &n, &k);
    vector<ll> c(n+1);
    priority_queue<Pll> que;
    c[0] = 0LL;
    rep(n){
        scanf("%lld", &c[i+1]);
    }

    ll ans = 0LL;
    vector<ll> schedule(n+1);
    reppp(t, 1, k){
        que.push(Pll(c[t], t));
    }
    reppp(t, 1+k, k+n){
        if(t <= n) que.push(Pll(c[t], t));
        Pll p = que.top(); que.pop();
        ans += p.first * (t-p.second);
        schedule[p.second] = t;
    }
    printf("%lld\n", ans);
    printf("%lld", schedule[1]);
    reppp(i, 2, n){
        printf(" %lld", schedule[i]);
    }
    printf("\n");
}