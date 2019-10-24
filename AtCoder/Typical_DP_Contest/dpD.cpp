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
#define EPS 1e-18
#define DEBUG 0

using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

ll a[3];

ll prime_factor(ll d, ll p){
    ll cnt = 0;
    while(d % p == 0){
        d /= p;
        cnt++;
    }
    return cnt;
}

void primes_factor(ll d){
    a[0] = prime_factor(d, 2);
    a[1] = prime_factor(d, 3);
    a[2] = prime_factor(d, 5);
}

signed main(){
    ll n, d;
    cin >> n >> d;

    primes_factor(d);
    if(pow(2, a[0]) * pow(3, a[1]) * pow(5, a[2]) != d){
        printf("%.9lf\n", 0.0);
        return 0;
    }
    int n2 = 61, n3 = 39, n5 = 27;
    double dp[2][n2][n3][n5];
    
    repp(nn, 2){
        repp(i, n2){
            repp(j,n3){
                repp(k, n5){
                    dp[nn][i][j][k] = 0;
                }
            }
        }
    }
    
    dp[0][0][0][0] = 1.0;

    repp(nn, n){
        int m = nn % 2;
        repp(i, n2){
            repp(j, n3){
                repp(k, n5){
                    double tmp = dp[m][i][j][k] / 6;
                    dp[1-m][i][j][k] += tmp;
                    dp[1-m][min(n2-1, i+1)][j][k] += tmp;
                    dp[1-m][i][min(n3-1, j+1)][k] += tmp;
                    dp[1-m][min(n2-1, i+2)][j][k] += tmp;
                    dp[1-m][i][j][min(n5-1, k+1)] += tmp;
                    dp[1-m][min(n2-1, i+1)][min(n3-1, j+1)][k] += tmp;
                }
            }
        }
        if(nn != n-1) repp(i, n2)repp(j, n3)repp(k, n5) dp[m][i][j][k] = 0.0;
    }
    
    double ans = 0.0;
    
    reppp(i, a[0], n2-1){
        reppp(j, a[1], n3-1){
            reppp(k, a[2], n5-1){
                ans += dp[n%2][i][j][k];
            }
        }
    }
    

    if(DEBUG)
        repp(i, n2){
            repp(j,n3){
                repp(k, n5){
                    if(dp[1][i][j][k] != 0) printf("dp[%d][%d][%d] = %.9lf\n", i, j, k, dp[1][i][j][k]);
                }
            }
        }
    

    printf("%.9lf\n", ans);
    return 0;

}