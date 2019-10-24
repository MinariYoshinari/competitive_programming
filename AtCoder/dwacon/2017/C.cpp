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

map<int, ll> a,b;
ll partitions[101][1001];

ll solve(int n, map<int, ll> a, ll death){
    int group = (int)a.size();
    ll dp[group+1][death+1];
    fill(dp[0], dp[group+1], 0);
    int i = 0;
    for(auto itr=a.begin();itr!=a.end();++itr){
        repp(j, death+1){
            if(i == 0){
                dp[0][j] = partitions[itr->second][j];
            }else{
                repp(jj, j+1) dp[i][j] += (dp[i-1][jj] * partitions[itr->second][j-jj]) % MOD;
                dp[i][j] %= MOD;
            }
        } 
        i++;
    }
    return dp[group-1][death];
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, m, tmp;
    ll death_a = 0, death_b = 0;
    cin >> n >> m;
    rep(n){
        cin >> tmp;
        a[tmp]++;
        death_b += tmp;
    }
    rep(m){
        cin >> tmp;
        b[tmp]++;
        death_a += tmp;
    }

    partitions[0][0] = 1LL;
    reppp(i, 1, 101){
        reppp(j, 0, 1001){
            if(j-i >= 0){
                partitions[i][j] = (partitions[i-1][j] + partitions[i][j-i]) % MOD;
            }else{
                partitions[i][j] = partitions[i-1][j];
            }
        }
    }

    cout << (solve(n, a, death_a) * solve(m, b, death_b)) % MOD << endl;
}
