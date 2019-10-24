#include <bits/stdc++.h>

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

ll x, y, d;

ll extgcd(ll a, ll b, ll &x, ll &y){
    d = a;
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        d = extgcd(b, a%b, y, x);
        y -= a/b * x;
    }
    return d;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll a,b;
    cin >> a >> b;
    extgcd(a,b, x,y);
    cout << x << " " << y << endl;
}
