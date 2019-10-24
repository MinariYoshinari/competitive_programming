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

string s;
ll dp[200001];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> s;
    int n = (int)s.length();

    rep(n){
        dp[i+1] = dp[i] ^ (1LL << (s[i]-'a'));
    }

    vector<int> opt(n+1, INF), dpdp(pow(2, 26), INF);
    dpdp[0] = INF;
    opt[0] = 1;
    opt[1] = 1;
    reppp(i, 1, n){
        dpdp[i] = min(dpdp[i-1], opt[dp[i-1]]);
        repp(x, pow(2, 26)){
            dpdp
        }
    }


}
