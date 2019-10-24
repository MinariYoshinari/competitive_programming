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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll a;
    cin >> a;
    ll b = 10;
    ll ans = 0;
    ll lcm = a * 10 / gcd(a, 10);
    ll ans_tmp = 0;
    while(lcm > 0){
        ans_tmp += lcm % 10;
        lcm /= 10;
    }
    cout << ans << endl;
}