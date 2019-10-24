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
    ios::sync_with_stdio(false); cin.tie(0);

    ll x, k, q, t, aa, diff;
    cin >> x >> k;
    vector<ll> r(k), a(k), b(k), c(k);
    rep(k){
        cin >> r[i];
        if(i > 0) diff = r[i] - r[i-1];
        if(i == 0){
            if(r[i] > x){
                a[i] = 0;
                b[i] = 0;
                c[i] = 0;
            }else{
                a[i] = r[i];
                b[i] = x;
                c[i] = -r[i];
            }
        }else if(i % 2 == 0){
            if(b[i-1] + c[i-1] - diff <= 0){
                a[i] = 0;
                b[i] = 0;
                c[i] = 0;
            }else{
                if(a[i-1] + c[i-1] - diff <= 0){
                    a[i] = c[i-1] + diff;
                }else{
                    a[i] = max(a[i-1], - c[i-1] + diff);
                }
                b[i] = b[i-1];
                c[i] = c[i-1] - diff;
            }
        }else{
            if(a[i-1]+c[i-1]+diff >= x){
                a[i] = 0;
                b[i] = 0;
                c[i] = x;
            }else{
                a[i] = a[i-1];
                if(b[i-1]+c[i-1]+diff >= x){
                    b[i] = - c[i-1] + x - diff;
                }else{
                    b[i] = min(b[i-1], - c[i-1] + (x - diff));
                }
                c[i] = c[i-1] + diff;
            }
        }
    }

    cin >> q;
    rep(q){
        cin >> t >> aa;
        ll ans, ii = (ll)(upper_bound(all(r), t) - r.begin()) - 1;

        if(ii == -1){
            cout << max(0LL, aa - t) << endl;
            continue;
        }
        //cout << a[ii-1] <<  " " << b[ii-1] << " " << c[ii-1] << endl;
        //cout << a[ii] <<  " " << b[ii] << " " << c[ii] << endl;
        if(aa <= a[ii]){
            ans = a[ii] + c[ii];
        }else if(aa >= b[ii]){
            ans = b[ii] + c[ii];
        }else{
            ans = aa + c[ii];
        }

        if(ii % 2 == 1){
            ans = max(0LL, ans - (t - r[ii]));
        }else{
            ans = min(x, ans + (t - r[ii]));
        }
        
        cout << ans << endl;
    }
}
