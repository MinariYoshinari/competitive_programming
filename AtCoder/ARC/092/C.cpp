#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int to; ll cap; int rev;};

const ll MOD = 1000000007;
const double EPS = 1e-9;
const int MAX_V = 202;

vector<edge> G[MAX_V];
vector<int> level(MAX_V, -1);
vector<int> iter(MAX_V, 0);
int N, s, t;

void add_edge(int from, int to, ll cap){
    /*
        ある点vに対する辺の集合はvectorで管理されているので，
        そのvectorの中の何番目の辺に対応しているかを記憶する→rev
    */
    G[from].push_back({to, cap, (int)G[to].size()});
    G[to].push_back({from, 0, (int)G[from].size()-1});
}

void bfs(int s){
    level = vector<int>(MAX_V, -1);
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
        while((f = dfs(s, t, LLONG_MAX)) > 0){
            max_flow += f;
        }
    }

    return max_flow;
}


int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<Pll> red(N), blue(N);
    rep(N){
        cin >> red[i].first >> red[i].second;
        add_edge(0, i+1, 1);
    }
    rep(N){
        cin >> blue[i].first >> blue[i].second;
        add_edge(N+1+i, 2*N+1, 1);
    }
    rep(N){
        repp(j, N){
            if(red[i].first < blue[j].first && red[i].second < blue[j].second){
                add_edge(i+1, N+1+j, 1);
            }
        }
    }

    cout << dinic(0, 2*N+1) << endl;
}
