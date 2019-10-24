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
    ll n, m;
    scanf("%lld %lld", &n, &m);
    if(abs(n-m) > 1){
        printf("%d", 0);
        return 0;
    }
    if(n > m) swap(n, m);
    ll factn = 1, factm;
    reppp(i, 2, n){
        factn *= i;
        factn %= MOD;
    }
    factm = factn;
    reppp(i, n+1, m){
        factm *= i;
        factm %= MOD;
    }
    if(n == m){
        factn *= 2; 
        factn %= MOD;
    }
    printf("%lld", (factn * factm) % MOD);
    return 0;

}