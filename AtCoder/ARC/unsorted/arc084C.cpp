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
    ios::sync_with_stdio(0); cin.tie(0);
    int n, tmp;
    cin >> n;
    vector<Pii> a(3*n);
    rep(3*n){
        cin >> tmp;
        a[i] = Pii(tmp, 2-i/n);
    }
    sort(all(a));

    ll dp[3*n][3];
    fill(dp[0], dp[3*n], 0LL);

    if(a[0].second == 2) dp[0][2] = 1;


    reppp(i, 1, 3*n-1){
        for(int j=2; j>=0; j--){
            if(a[i].second != j){
                dp[i][j] = dp[i-1][j];
            }else{
                if(j == 2){
                    dp[i][2] = dp[i-1][2] + 1;
                }else{
                    dp[i][a[i].second] = dp[i-1][a[i].second] + dp[i][a[i].second+1];
                }
            }
        }
    }
    cout << dp[3*n-1][0];
}  
