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

vector<int> used(100000);
vector<ll> stones(100000);
vector<int> tree[100000];

int root = 0;

/*
葉から根に向かってチェックしていくdfs
返り値は (nodeを呼び出したノード) -> (node) の辺が使用されるべき回数
途中でNOであることが判明したらその地点でLLONG_MAXを返す
*/
ll dfs(int node){
    used[node] = 1;

    int n = (int)tree[node].size();

    /* 根でない葉ノードの場合 */
    if(node != root && n == 1) return stones[node];

    /* 中間ノードまたは根の場合 */
    vector<ll> edges(n+1, 0);
    ll total = 0;
    rep(n){
        if(used[tree[node][i]]) continue;
        edges[i] = dfs(tree[node][i]);
        total += edges[i];
        if(edges[i] == LLONG_MAX) return LLONG_MAX;
    }
    /* (nodeを呼び出したノード) -> (node) の辺が使用されるべき回数を求める */
    edges[n] = (stones[node]*2-total);
    if(edges[n] < 0) return LLONG_MAX;
    total += edges[n];
    for(ll edge: edges){
        if(edge > total/2) return LLONG_MAX;
    }
    return edges[n];
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(n) cin >> stones[i];
    rep(n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    /*
    根の周りのエッジの使用回数チェックを省略するため，
    根は次数が1のノード (葉) になるようにする
    */
    while(tree[root].size() > 1) root++;

    ll ret = dfs(root);
    cout << (ret==LLONG_MAX?"NO":"YES") << endl;

    return 0;
}
