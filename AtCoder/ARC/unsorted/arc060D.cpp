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

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(ll j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<=n;i++)
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

ll digit_sum(ll n, ll b){
    ll ret = 0;
    while(n >= b){
        ret += (n % b);
        n /= b;
    }
    ret += n;
    return ret;
}

signed main(){
    ll n, s;
    cin >> n >> s;
    
    if(n == s){
        cout << n+1;
        return 0;
    }

    reppp(b, 2, (ll)sqrt((double)n)){
        if(digit_sum(n, b) == s){
            cout << b;
            return 0;
        }
    }

    ll p = min(s, (ll)sqrt((double)n)), b;
    while(p > 0){
        if((n-s)%p == 0){
            b = (n-s)/p + 1;
            if(b > p && b > (s-p)){
                cout << b;
                return 0;
            }
        }
        p--;
    }

    cout << -1;
    return 0;
}