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

signed main(){
    int H, W;
    cin >> H >> W;

    vector<string> c(H);
    rep(H) cin >> c[i];
    
    int ans = 0;
    
    repp(k, W-1){
        vector< vector<int> > dp(H+1, vector<int>(H+1, INF));
        vector< vector<int> > costs(H+1, vector<int>(H+1, 0));
        dp[0][0] = 0;

        repp(i, H+1){
            repp(j, H+1){
                if(i == H && j == H) break;
                if(i == 0 || j == 0){
                    int ii = i, jj = j;
                    int base = min(i, j);
                    while(ii < H && jj < H){
                        if(c[jj-base][k] == c[ii-base][k+1]){
                            costs[i][j]++;
                        }
                        ii++;
                        jj++;
                    }
                }else{
                    costs[i][j] = costs[i-1][j-1];
                    if(c[H-i][k] == c[H-j][k+1]) costs[i][j]--;
                }
                // cout << i << " " << j << " " << costs[i][j] << endl;
                if(i < H) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + costs[i][j]);
                if(j < H) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + costs[i][j]);
            }
        }
        // cout << dp[H][H] << endl;
        ans += dp[H][H];
    }
    cout << ans;
}
