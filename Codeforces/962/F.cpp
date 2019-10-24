#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

vector<int> graph[100000];
vector<int> cnt(100000, 0);

struct UnionFind{
    int n;
    vector<int> par, depth,size;  //親, 深さ, その木の要素数

    UnionFind(int n){
        this->n = n;
        rep(n){
            par.push_back(i);
            depth.push_back(0);
            size.push_back(1);
        }
    }

    //根を求める
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            int p = find(par[x]);
            size[x] = size[p];
            return par[x] = p;
        }
    }

    //xとyの属する集合の併合
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        
        size[x] += size[y];
        size[y] += size[x];
        if(depth[x] < depth[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(depth[x] == depth[y]) depth[x]++;
        }
    }

    //同じ集合に属するか否か
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

vector<int> dfs(int node, int par, vector<int> path, vector<int> used){
    used[node] = 1;
    path.push_back(node);
    for(int next: graph[node]){
        if(next == par) continue;
        if(used[next]) return path;
        vector<int> v = dfs(next, node, path, used);
        if(!v.empty()){
            for(int x: v) cnt[x]++;
        }
    }
    return vector<int>();
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    UnionFind uf = UnionFind(n);
    rep(m){
        cin >> a >> b;
        a--; b--;
        uf.unite(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> par(uf.par);
    unique(all(par));

    for(int p: par){
        vector<int> v = dfs(p, -1, vector<int>(), vector<int>(n, 0));
    }

    int l = 0;
    rep(n) if(cnt[i] == 1) l++;

    cout << l << endl;
    rep(n) if(cnt[i] == 1) cout << i+1 << " ";
    cout << endl;
}
