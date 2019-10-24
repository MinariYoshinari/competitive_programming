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

int dp[2000][4];

int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    rep(n) scanf("%d", &a[i]);

    if(a[0] == 1) dp[0][0] = 1;
    else dp[0][0] = 0;
    reppp(j, 1, 4) dp[0][j] = 1;
    reppp(i, 1, n){
        if(a[i] == 1){
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + 1);
            dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2])) + 1;
            dp[i][3] = max(
                max(dp[i-1][0], dp[i-1][2]) + 1, 
                max(dp[i-1][1], dp[i-1][3])
                );
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + 1;
            dp[i][2] = max(max(dp[i-1][0], dp[i-1][1]) + 1, dp[i-1][2]);
            dp[i][3] = max(
                max(dp[i-1][0], dp[i-1][2]),
                max(dp[i-1][1], dp[i-1][3]) + 1
                );
        }
    }
    int ans = dp[n-1][3];
    rep(3) ans = max(ans, dp[n-1][i]);
    cout << ans << endl;
}

/*
4
1 2 1 2 

200
2 1 1 2 1 2 2 2 2 2 1 2 2 1 1 2 2 1 1 1 2 1 1 2 2 2 2 2 1 1 2 1 2 1 1 2 1 1 1 1 2 1 2 2 1 2 1 1 1 2 1 1 1 2 2 2 1 1 1 1 2 2 2 1 2 2 2 1 2 2 2 1 2 1 2 1 2 1 1 1 1 2 2 2 1 1 2 1 2 1 2 1 2 2 1 1 1 2 2 2 2 1 2 2 2 1 1 1 1 2 1 1 1 2 2 1 2 1 2 2 2 1 2 1 2 1 2 1 2 2 2 1 2 2 2 1 1 1 1 2 1 2 1 1 1 2 1 2 2 2 1 2 1 1 1 1 1 1 2 1 1 2 2 2 1 2 1 1 1 1 2 2 1 2 1 2 1 2 1 2 1 2 2 1 1 1 1 2 2 1 1 2 2 1 2 2 1 2 2 2
116
*/