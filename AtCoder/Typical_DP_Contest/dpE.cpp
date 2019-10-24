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
    string s; int d,n;
    cin >> d >> s;
    n = (int)s.length();

    int dp[n][d];
    fill(dp[0], dp[n], 0);
    int dp9[n-1][d];
    fill(dp9[0], dp9[n-1], 0);

    for(int i=n-2;i>=0;i--){
        if(i == n-2){
            repp(j, 10){
                dp9[i][j%d]++;
            }
        }else{
            repp(j, 10){
                repp(k, d){
                    (dp9[i][(j+k)%d] += dp9[i+1][k]) %= MOD;
                }
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        int num = (int)(s[i] - '0');
        if(i == n-1){
            repp(j, d){
                dp[n-1][j] = (num < d)? ((j <= num)? 1 : 0) : (num-j)/d+1;
            }
        }else{
            repp(j, d){
                repp(k, num){
                    (dp[i][(j+k)%d] += dp9[i][j]) %= MOD;
                }
                (dp[i][(num+j)%d] += dp[i+1][j]) %= MOD;
            }
        }
        /*
        repp(j, d){
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
        */
    }

    cout << dp[0][0] - 1 << endl;
}
