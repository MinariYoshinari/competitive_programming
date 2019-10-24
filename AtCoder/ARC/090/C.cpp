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
typedef pair<int, Pii> Piii;
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[2][n];
    rep(2)repp(j,n) cin >> a[i][j];

    priority_queue<Piii> que;
    que.push(Piii(a[0][0], Pii(0, 0)));
    int ans = 0;
    while(!que.empty()){
        Piii p = que.top(); que.pop();

        if(p.second.first == 1 && p.second.second == n-1){
            ans = max(ans, p.first);
        }

        if(p.second.first == 0){
            que.push(Piii(p.first + a[1][p.second.second], Pii(1, p.second.second)));
        }
        if(p.second.second != n-1){
            que.push(Piii(p.first + a[p.second.first][p.second.second+1], Pii(p.second.first, p.second.second+1)));
        }
    }
    cout << ans << endl;
}
