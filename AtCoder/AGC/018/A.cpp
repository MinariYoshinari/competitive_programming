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
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

signed main(){
    int n; ll k, tmp, m, g;
    cin >> n >> k;
    vector<ll> a;
    rep(n){
        cin >> tmp;
        a.pb(tmp);
    }
    m = *max_element(all(a));
    if(m < k){
        cout << "IMPOSSIBLE";
        return 0;
    }

    g = a[0];
    reppp(i, 1, n-1){
        g = gcd(g, a[i]);
    }
    
    if(k % g == 0){
        cout << "POSSIBLE";
    }else{
        cout << "IMPOSSIBLE";
    }

    return 0;
}
