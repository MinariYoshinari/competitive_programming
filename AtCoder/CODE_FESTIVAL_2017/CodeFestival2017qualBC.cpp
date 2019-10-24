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
#define MAX 100000
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

//int G[MAX][MAX];
vector<int> G[MAX];
set<Pii> Gadd;
int ans = 0;

void dfs(int start, int node, int depth){
    //printf("dfs(%d, %d, %d)\n", start+1, node+1, depth);
    for(int next: G[node]){
        if(depth + 1 == 3){
            if(start != next){
                Gadd.insert(Pii(start, next));
                //printf("%d->%d\n", start+1, next+1);
            }
        }else{
            //printf("dfs(%d, %d, %d)\n", start+1, node+1, depth);
            dfs(start, next, depth+1);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, from, to;
    cin >> n >> m;
    rep(m){
        cin >> from >> to;
        from--; to--;
        G[from].pb(to);
        G[to].pb(from);
    }

    rep(n){
        dfs(i, i, 0);
        for(Pii p: Gadd){
            if(find(all(G[p.first]), p.second) == G[p.first].end()){
                G[p.first].pb(p.second);
                G[p.second].pb(p.first);
                ans++;
            }
        }
        Gadd.clear();
    }
    cout << ans;
}
