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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin >> n >> k;
    if(k == 1){
        cout << "Yes" << endl;
        return 0;
    }
    ll m = 1;
    for(ll i=2;i<=min(k, 43LL);i++){
        m = m * i / gcd(m, i);
    }
    if((n+1)%m == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
