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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
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

ll powmod(ll a, ll t){
    ll ret = 1;
    while(t){
        if(t & 1){
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        t >>= 1;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout << powmod(2, 100) << endl;
    int n,p;
    cin >> n;
    vector<int> depth(n+1, 0), children(n+1, 0), depth_count(n+1, 0);
    vector<int> depth_vec[n+1];
    depth_count[0] = 1;
    depth_vec[0].push_back(0);
    for(int i=1;i<=n;i++){
        cin >> p;
        depth[i] = depth[p]+1;
        depth_count[depth[i]]++;
        children[p]++;
        depth_vec[depth[i]].push_back(i);
    }

    ll ans = 0LL;
    rep(n+1){
        if(depth_count[i] == 0) break;
        ll pow_ = powmod(2, n+1-depth_count[i]);

        if(i != 0){
            ll a = 0;
            for(int p: depth_vec[i-1]){
                ll b = 1;
                for(int q: depth_vec[i-1]){
                    if(q == p){
                        b *= children[p];
                        //b %= MOD;
                    }else{
                        b *= powmod(2, children[q]) - children[q];
                        //b %= MOD;
                    }
                }
                a += b;
                // a %= MOD;
            }
            ans += (pow_ * a);// % MOD;
            // ans %= MOD;
        }else{
            ans += pow_;
            // ans %= MOD;
        }
    }

    cout << ans % MOD << endl;


}
