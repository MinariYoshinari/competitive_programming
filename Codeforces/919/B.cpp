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

ll dp[10][11];
int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll k;
    cin >> k;
    if(k <= 9){
        cout << k*10+(10-k) << endl;
        return 0;
    }

    repp(j, 10){
        dp[1][j] = 1;
    }
    reppp(i, 2, 10){
        dp[i][0] = 1;
        reppp(j, 1, 10){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
        dp[i][10] = dp[i][9] - 1 + dp[i-1][10];
        /*
        repp(j, 11){
            printf("%5lld ", dp[i][j]);
        }
        printf("\n");
        */
    }

    ll digit = 2, rest = 10;
    while(k > dp[digit][10]) digit++;
    while(true){
        if(k <= dp[2][rest]){
            rep(digit-2) cout << 0;
            cout << k-1 << rest-k+1 << endl;
            return 0;
        }
        ll d = rest;
        digit--;
        while(k > dp[digit][d]){
            k -= dp[digit][d];
            // cout << "*" << k << endl;
            d--;
        }
        cout << rest-d;
        rest -= rest-d;
    }
    return 0;
}
