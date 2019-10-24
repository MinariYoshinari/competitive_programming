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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int k, n;
    cin  >> k;
    n = pow(2, k);
    vector< vector<double> > dp(k+1, vector<double>(n, 0));
    repp(j, n) cin >> dp[0][j];

    for(int j=0;j<n;j+=2){
        dp[1][j] = 1.0 / (1.0 + pow(10.0, (dp[0][j+1] - dp[0][j]) / 400));
        dp[1][j+1] = 1.0 / (1.0 + pow(10.0, (dp[0][j] - dp[0][j+1]) / 400));
    }

    int pi = 4, pi1 = 2;
    reppp(i, 2, k){
        repp(j, n){
            int jj = j / pi * pi;
            reppp(l, jj, jj + pi-1){
                if(j / pi1 != l / pi1){
                    dp[i][j] += dp[i-1][l] * 1.0 / (1.0 + pow(10.0, (dp[0][l] - dp[0][j]) / 400));
                }
            }
            dp[i][j] *= dp[i-1][j];
        }
        pi1 = pi;
        pi *= 2;
    }

    repp(j, n) printf("%.9lf\n", dp[k][j]);
}