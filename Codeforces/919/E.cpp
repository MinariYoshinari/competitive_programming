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
#define MOD 1000000007
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

ll powmod(ll a, ll t){
    ll ret = 1;
    while(t){
        if(t & 1){
            ret = productmod(ret, a);
        }
        a = productmod(a, a);
        t >>= 1;
    }
    return ret;
}

int main(){
    ll a,b,p,x;
    scanf("%lld %lld %lld %lld", &a, &b, &p, &x);

    ll ans = 0LL, y = 0LL;
    ll a2 = powmod(a, p-2);
    ll tmp = (b * a2) % p;
    reppp(i, 1, p){
        if(i == tmp){
            y = i;
            break;
        }
        (tmp *= a2) %= p;
    }
    cout << y << endl;
    x -= y;
    ans += x/p;
    if(x%p >= y) ans++;

    printf("%lld\n", ans);
}