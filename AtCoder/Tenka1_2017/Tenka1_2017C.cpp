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

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-12
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<=n;i++)
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll N;
    cin >> N;
    vector< tuple<double, ll, ll, ll> > ans;
    reppp(h, 1, 3500){
        reppp(n, 1, 3500){
            // okは大きいか正しい, ngは小さすぎ
            ll ok = 3500, ng = 0, w;
            while(ng < ok){
                if((ng + ok)/2 == w) break;
                w = (ng+ok) / 2;
                double diff =  (double)((h*n+n*w+w*h) * N)/(4*h*n*w) - 1.0;
                if(abs(diff) <= EPS){
                    //printf("%lld %lld %lld\n", h, n, w);
                    ans.pb(make_tuple(diff, h, n, w));
                    break;
                }
                if(diff < 0.0){
                    ok = w;
                }else{
                    ng = w+1;
                }
            }
        }
    }
    sort(all(ans));
    printf("%lld %lld %lld\n", get<1>(ans[0]), get<2>(ans[0]), get<3>(ans[0]));
}
