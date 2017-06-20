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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define MAX_V 100000
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int to; ll cap; int rev;};

vector<edge> G[MAX_V];
int H, W, s, t;

void add_edge(int from, int to, ll cap){
    /*
        ある点vに対する辺の集合はvectorで管理されているので，
        そのvectorの中の何番目の辺に対応しているかを記憶する→rev
    */
    G[from].push_back({to, cap, (int)G[to].size()});
    G[to].push_back({from, 0, (int)G[from].size()-1});
}

ll dfs(int v, int t, ll f, vector<bool> used){
    if(v == t) return f;
    used[v] = true;
    rep((int)G[v].size()){
        edge &e = G[v][i]; //eの中身を書き換えたいのでポインタを使用
        if(!used[e.to] && e.cap > 0){
            ll d = dfs(e.to, t, min(f, e.cap), used);
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll ford_fulkerson(int s, int t){
    ll max_flow = 0;

    while(true){
        vector<bool> used(MAX_V, false);
        ll f = dfs(s, t, INF, used);
        if(f == 0) break;
        max_flow += f;
    }

    return max_flow;
}

signed main(){
    cin >> H >> W;
    rep(H){
        string tmp;
        cin >> tmp;
        repp(j, W){
            if(tmp[j] == 'S'){
                s = W*i + j;
                add_edge(W+H, i, INF);
                add_edge(W+H, H+j, INF);
            }else if(tmp[j] == 'T'){
                t = W*i + j;
                add_edge(i, W+H+1, INF);
                add_edge(H+j, W+H+1, INF);
            }else if(tmp[j] == 'o'){
                add_edge(i, H+j, 1);
                add_edge(H+j, i, 1);
            }
        }
    }
    
    if(s / W == t / W || s % W == t % W){
        cout << -1;
    }else{
        cout << ford_fulkerson(W+H, W+H+1);
    }
}
