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
    int n;
    cin  >> n;
    vector<int> a(n);
    rep(n) cin >> a[i];

    vector< vector<int> > dp(n, vector<int>(100*n+1, 0));
    dp[0][0] = 1;
    dp[0][a[0]] = 1;
    repp(i, n-1){
        repp(j, (int)dp[i].size()){
            if(dp[i][j] == 1){
                dp[i+1][j] = 1;
                dp[i+1][j+a[i+1]] = 1;
            }
        }
    }

    cout << count_if(all(dp[n-1]), [](int m)->bool{return (m == 1);}) << endl;
}