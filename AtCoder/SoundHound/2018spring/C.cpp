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
struct edge{int to; ll cap; int rev;};

vector<edge> G[40*40+2];
vector<int> level(40*40+2, -1);
vector<int> iter(40*40+2, 0);
int r, c, s, t;

void add_edge(int from, int to, ll cap){
    /*
        ある点vに対する辺の集合はvectorで管理されているので，
        そのvectorの中の何番目の辺に対応しているかを記憶する→rev
    */
    G[from].push_back({to, cap, (int)G[to].size()});
    G[to].push_back({from, 0, (int)G[from].size()-1});
}

void bfs(int s){
    level = vector<int>(40*40+2, -1);

    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(edge e : G[v]){
            if(e.cap > 0 && level[e.to] == -1){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

ll dfs(int v, int t, ll f){
    if(v == t) return f;
    rep((int)G[v].size()){
        edge &e = G[v][i]; //eの中身を書き換えたいのでポインタを使用
        if(level[v] < level[e.to] && e.cap > 0){
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll dinic(int s, int t){
    ll max_flow = 0;
    while(true){
        bfs(s);
        if(level[t] < 0) return max_flow;
        ll f;
        while((f = dfs(s, t, 10000)) > 0){
            max_flow += f;
        }
    }

    return max_flow;
}

signed main(){
    int n = 0;
    cin >> r >> c;
    string field[r];
    rep(r){
        cin >> field[i];
        repp(j, c){
            if(field[i][j] == '.'){
                n++;
                if((i+j) % 2){
                    add_edge(c*i+j+1, r*c+1, 1);
                }else{
                    add_edge(0, c*i+j+1, 1);
                }
            }
        }
    }

    rep(r){
        repp(j, c){
            if((i+j) % 2) continue;
            if(field[i][j] == '.'){
                if(i > 0 && field[i-1][j] == '.') add_edge(c*i+j+1, c*(i-1)+j+1, 1);
                if(i < r-1 && field[i+1][j] == '.') add_edge(c*i+j+1, c*(i+1)+j+1, 1);
                if(j > 0 && field[i][j-1] == '.') add_edge(c*i+j+1, c*i+j, 1);
                if(j < c-1 && field[i][j+1] == '.') add_edge(c*i+j+1, c*i+j+2, 1);
            }
        }
    }
    
    cout << n-dinic(0, r*c+1);
}
