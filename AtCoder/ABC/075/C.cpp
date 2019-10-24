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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;

int G[51][51];
vector<int> used(51);
int n, m;

int dfs(int node, vector<int> used, int depth){
    used[node] = 1;
    if(depth == n) return *min_element(all(used));

    reppp(i, 1, n+1){
        if(G[node][i]) if(dfs(i, used, depth+1)) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, ans = 0;
    cin >> n >> m;
    
    vector<Pii> edges;
    rep(m){
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
        edges.emplace_back(a, b);
    }

    for(Pii e: edges){
        vector<int> v(n+1, 0);
        v[0] = 1;
        swap(used, v);
        G[e.first][e.second] = 0;
        G[e.second][e.first] = 0;
        int bridge = 0;
        rep(n){
            if(dfs(i+1, used, 1)){
                bridge = 1;
                break;
            }
        }
        ans += 1-bridge;
        cout << ans << endl;
        G[e.first][e.second] = 1;
        G[e.second][e.first] = 1;
    }

    cout << ans;
    
}
