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

ll mypow(ll p, ll n){
    ll ret = 1;
    rep(n){
        ret *= p;
        if(LLONG_MAX / p <= ret){
            return LLONG_MAX;
        }
    }
    return ret;
}

signed main(){
    ll N, A;
    cin >> N >> A;

    if(N<=3){
        cout << N << endl;
        return 0;
    }
    
    ll ans = N;
    reppp(k, 1, 20){
        ll ok = 10e12;
        ll ng = 1;
        while(abs(ok-ng) > 1){
            ll mid = (ok+ng)/2;
            ll tmp = mypow(mid, (ll)(k+1));
            if(tmp >= N || tmp == LLONG_MAX){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll s1_num = 0;
        while(s1_num <= k && pow(ok-1, s1_num) * pow(ok, k+1-s1_num) >= N) s1_num++;
        if(s1_num < k+1 || pow(ok-1, s1_num) * pow(ok, k+1-s1_num) < N) s1_num--;
        //cout << k << " " << ok << " " << s1_num << endl;
        ans = min(ans, A*k + (ok-1)*s1_num + ok*(k+1-s1_num));
        //cout << A*k + (ok-1)*s1_num + ok*(k+1-s1_num) << endl;
    }
    cout << ans << endl;
    return 0;
}