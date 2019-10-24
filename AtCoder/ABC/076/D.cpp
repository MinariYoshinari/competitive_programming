/* 後は提出するだけ */
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
#define MOD 1000000007LL
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
    int n;
    cin >> n;
    vector<double> t(n+2, 0), v(n+2, 0);
    rep(n){
        cin >> t[i+1];
        t[i+1] += t[i];
    }
    t[n+1] = t[n];
    rep(n) cin >> v[i];

    double ans = 0.0;
    double vv = 0.0, prev_vv;
    for(double tt=0.5;tt<=t.back();tt+=0.5){
        prev_vv = vv;
        vv += 0.5;
        rep(n+2){
            if(tt <= t[i]){
                vv = min(vv,  v[i] + (t[i]-tt));
            }else if(tt <= t[i+1]){
                vv = min(vv, v[i]);
            }else{
                vv = min(vv, v[i] + (tt-t[i]));
            }
        }
        if(prev_vv <= vv){
            ans += prev_vv * 0.5 + (vv-prev_vv) * 0.25;
        }else{
            ans += vv * 0.5 + (prev_vv-vv) * 0.25;
        }
    }
    printf("%.4lf", ans);
}