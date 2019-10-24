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

int x[20], children[1<<20], sumx[1<<20];

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(n) cin >> x[i];
    reppp(i, 1, n){
        int tmp;
        cin >> tmp;
        children[tmp-1] |= (1 << i);
    }
    rep(1<<n){
        repp(j, n){
            if(i & (1 << j)) continue;
            if(sumx[i | (1 << j)]) continue;
            sumx[i | (1 << j)] = sumx[i] + x[j];
        }
    }
    
    int dp[1<<n];
    fill(dp, dp+(1<<n), INT_MAX);
    dp[0] = 0;
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;
    que.emplace(dp[0], 0);
    while(!que.empty()){
        int usage, bs;
        tie(usage, bs) = que.top(); que.pop();
        // cout << static_cast< bitset<5> >(bs) << ":" << dp[bs] << endl;
        if(dp[bs] < usage) continue;
        
        repp(j, n){
            if((bs & (1 << j)) || ((bs & children[j]) != children[j])) continue;

            int nxt = (bs | (1 << j)) & ~children[j];
            if(dp[nxt] > max(dp[bs], sumx[bs | (1 << j)])){
                dp[nxt] = max(dp[bs], sumx[bs | (1 << j)]);
                que.emplace(dp[nxt], nxt);
                // cout << "->" << static_cast< bitset<5> >(nxt) << ":" << dp[nxt] << endl;
            }

        }
    }
    cout << dp[1] << endl;
}