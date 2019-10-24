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
#include<bitset>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007LL
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

ll productmod(ll x, ll y){
  if(x*y >= MOD) return (x*y) % MOD;
  else return x*y;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    scanf("%d", &n);
    vector<Pii> a(2*n);
    rep(n){
        scanf("%d", &a[i].first);
        a[i].second = 1;
    }
    rep(n){
        scanf("%d", &a[n+i].first);
        a[n+i].second = 0;
    }
    sort(all(a));
    ll ans = 1LL;
    ll cnt[2] = {0, 0};
    rep(2*n){
        if(cnt[1-a[i].second] == 0){
            cnt[a[i].second]++;
        }else{
            ans = productmod(ans, cnt[1-a[i].second]);
            cnt[1-a[i].second]--;
        }
    }
    printf("%lld\n", ans);
}
