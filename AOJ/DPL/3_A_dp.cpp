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
#include<bitset>

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
    int h,w;
    cin >> h >> w;
    int area[h][w], dp[h][w], ans = 0;
    repp(i, h) repp(j, w) cin >> area[i][j];

    dp[0][0] = 1-area[0][0];
    ans = dp[0][0];
    reppp(j, 1, w){
        if(!area[0][j]) dp[0][j] = 1;
        else dp[0][j] = 0;
        ans = max(dp[0][j], ans);
    }
    reppp(i, 1, h){
        if(!area[i][0]) dp[i][0] = 1;
        else dp[i][0] = 0;
        ans = max(dp[i][0], ans);
    }
    reppp(i, 1, h){
        reppp(j, 1, w){
            if(!area[i][j]) dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            else dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans*ans << endl;
    return 0;
}
