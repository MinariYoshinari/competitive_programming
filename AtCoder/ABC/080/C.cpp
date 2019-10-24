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

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int f[n][10];
    ll p[n][11];

    rep(n) repp(j, 10) cin >> f[i][j];
    
    rep(n) repp(j, 11) cin >> p[i][j];

    ll ans = LLONG_MIN;
    int a[10];
    reppp(i, 1, 1023){
        int pattern = i, j = 0;
        while(j < 10){
            a[j] = pattern % 2;
            pattern /= 2;
            j++;
        }

        ll ans_tmp = 0;
        repp(k, n){
            int cnt = 0;
            repp(j, 10){
                if(f[k][j] == 1 && a[j] == 1) cnt++;
            }
            ans_tmp += p[k][cnt];
        }
        ans = max(ans, ans_tmp);
    }
    cout << endl << ans << endl;
}
