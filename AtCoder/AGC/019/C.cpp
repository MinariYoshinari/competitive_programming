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

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    
    int n;
    cin >> n;
    vector< Pii > v(n);
    rep(n){
        cin >> v[i].first >> v[i].second;
        if(sx > gx) v[i].first = 100000000 - v[i].first;
        if(sy > gy) v[i].second = 100000000 - v[i].second;
    }
    if(sx > gx){
        sx = 100000000 - sx;
        gx = 100000000 - gx;
    }
    if(sy > gy){
        sy = 100000000 - sy;
        gy = 100000000 - gy;        
    }
    sort(all(v));

    vector<int> y, lis;
    rep(n){
        if(sx <= v[i].first && v[i].first <= gx && min(sy, gy) <= v[i].second && v[i].second <= max(sy, gy)){
            y.push_back(v[i].second);
        }
    }
    for(int yy: y){
        auto itr = lower_bound(all(lis), yy);
        if(itr == lis.end()){
            lis.push_back(yy);
        }else{
            *itr = yy;
        }
    }

    int m = (int)lis.size();
    long double ans = 100.0 * (long double)(gx-sx + abs(gy-sy)) - (long double)m * 20.0;
    if(m == min(gx-sx, abs(gy-sy)) + 1){
        ans += 10.0 * PI;
        m--;
    }
    ans += (long double)m * 5.0 * PI;

    printf("%.15Lf\n", ans);
    return 0;
}