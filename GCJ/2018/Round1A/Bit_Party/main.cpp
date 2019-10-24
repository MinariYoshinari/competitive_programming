#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const double EPS = 1e-9;

ll m[5],s[5],p[5];
ll ans = LLONG_MAX;
int r,c,b;

void rec(int robots, int bits, vector<int> v){
    if(robots == 1){
        if(bits > m[r-1]) return;
        v.push_back(bits);
        ll ret = 0;
        rep(r){
            if(v[i] == 0) continue;
            ret = max(ret, p[i] + s[i] * (ll)v[i]);
            if(ret > ans) return;
        }
        if(ret == 0) return;
        
        /*
        if(ret < ans){
            for(int x: v) cerr << x << " ";
            cerr << endl;
        }
        */
        
        ans = ret;
        return;
    }

    rep(min(bits, (int)m[r-robots])+1){
        v.push_back(i);
        rec(robots-1, bits-i, v);
        v.pop_back();
    }
}

void solve(int tt){
    ans = LLONG_MAX;
    scanf("%d %d %d", &r, &b, &c);
    rep(c) scanf("%lld %lld %lld", &m[i], &s[i], &p[i]);

    rec(r, b, vector<int>());

    printf("Case #%d: %lld\n", tt+1, ans);
}

int main(){
    int t;
    scanf("%d", &t);

    repp(tt, t) solve(tt);
}
