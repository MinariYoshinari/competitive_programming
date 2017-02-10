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
#define MOD 1000000007
#define MAX 10000
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

edge es[MAX];
int V = 7, E = 18;

int par[MAX];  //親
int depth[MAX]; //深さ

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
  sort(es, es + E, comp);
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

signed main(){
  es[0] = {0, 2, 1};
  es[1] = {1, 2, 2};
  es[2] = {2, 3, 3};
  es[3] = {1, 4,10};
  es[4] = {2, 5, 7};
  es[5] = {4, 5, 5};
  es[6] = {3, 6, 5};
  es[7] = {5, 6, 8};
  es[8] = {3, 5, 1};
  rep((int)E/2){
	es[i+9] = {es[i].to, es[i].from, es[i].cost};
  }

  printf("%lld\n", kruskal());
}
