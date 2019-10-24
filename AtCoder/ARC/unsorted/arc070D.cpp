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

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(ll j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int n, k;

bool check(vector<int> b, int aa){
    vector< vector<bool> > dp(n-1, vector<bool>(k, false));
    dp[0][0] = true;
    if(b[0] < k) dp[0][b[0]] = true;
    reppp(i, 1, n-2){
        repp(j, k){
            if(dp[i-1][j]){
                dp[i][j] = true;
                if(b[i] < k-j) dp[i][j+b[i]] = true;
            }
        }
    }

    reppp(j, max(0, k-aa), k-1){
        if(dp[n-2][j]) return true;
    }
    return false;
}

signed main(){
    cin >> n >> k;
    vector<int> a(n);
    rep(n){
        cin >> a[i];
    }

    if(n == 1){
        if(a[0] >= k){
            cout << 0;
        }else{
            cout << 1;
        }
        return 0;
    }

    sort(all(a));

    int ok = n, ng = -1, m;
    while(ok - ng > 1){
        m = (ok+ng)/2;
        vector<int> b;
        rep(n){
            if(i == m) continue;
            b.pb(a[i]);
        }
        if(check(b, a[m])){
            ok = m;
        }else{
            ng = m;
        }
        //cout << m << endl;
        //cout << ng << " " << ok << endl;
    }
    
    cout << ng+1;
    return 0;
}