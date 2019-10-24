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
#define MAX 100005
#define INF 3000000000
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

ll V, E;
vector<edge> es;
int par[MAX];  //親
int depth[MAX]; //深さ

bool mylesser(pair<Pll,int> a, pair<Pll,int> b){
    return a.first.second < b.first.second;
}
//初期化
void init(int n){
    rep(n){
        par[i] = i;
        depth[i] = 0;
    }
}

//根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

//xとyの属する集合の併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
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

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

ll kruskal(){
  sort(all(es), comp);
  init(V);
  ll res = 0;

  rep(E){
    edge e = es[i];
    if(!same(e.from, e.to)){
      res += e.cost;
      unite(e.from, e.to);
    }
  }
  
  return res;
}

int main(){
    scanf("%lld", &V);
    vector< pair<Pii, int> > p(V);
    rep(V){
        scanf("%d %d", &p[i].first.first, &p[i].first.second);
        p[i].second = i;
    }
    sort(all(p));
    rep(V-1){
        Pll vvi = p[i].first, wwi = p[i+1].first;
        ll cost = (ll)min(abs(vvi.first - wwi.first), abs(vvi.second - wwi.second));
        edge e = {p[i].second, p[i+1].second, cost};
        es.pb(e);
        swap(e.from, e.to);
        es.pb(e);
    }
    sort(all(p), mylesser);
    rep(V-1){
        Pll vvi = p[i].first, wwi = p[i+1].first;
        ll cost = (ll)min(abs(vvi.first - wwi.first), abs(vvi.second - wwi.second));
        edge e = {p[i].second, p[i+1].second, cost};
        es.pb(e);
        swap(e.from, e.to);
        es.pb(e);
    }
    E = 4 * (V-1);
    printf("%lld\n", kruskal());
    return 0;
}