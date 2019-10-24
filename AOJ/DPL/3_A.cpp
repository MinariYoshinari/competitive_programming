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
    scanf("%d %d", &h, &w);
    int area[h][w], dp[h][w];
    repp(i, h) repp(j, w) scanf("%d", &area[i][j]);
 
    dp[0][0] = area[0][0];
    reppp(j, 1, w) dp[0][j] = dp[0][j-1] + area[0][j];
    reppp(i, 1, h) dp[i][0] = dp[i-1][0] + area[i][0];
    reppp(i, 1, h){
        reppp(j, 1, w){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + area[i][j];
        }
    }
 
 
    int ng = min(h,w) + 1, ok = 0;
    while(ng - ok > 1){
        int mid = (ng+ok)/2, flag = 0, sq = 0;
        reppp(i, mid-1, h){
            reppp(j, mid-1, w){
                sq = dp[i][j];
                if(i-mid >= 0) sq -= dp[i-mid][j];
                if(j-mid >= 0) sq -= dp[i][j-mid];
                if(i-mid >= 0 && j-mid>=0) sq += dp[i-mid][j-mid];
                if(sq == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
 
        if(flag){
            ok = mid;
        }else{
            ng = mid;
        }
    }
 
    printf("%d\n", ok*ok);
 
}