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
#define MAX 50000
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

edge es[MAX];
int N = 5, M = 5, R = 8;

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
  sort(es, es + 2*R, comp);
  init(N+M);
  ll res = 0;

  rep(2*R){
	edge e = es[i];
	if(!same(e.from, e.to)){
	  res += e.cost;
	  unite(e.from, e.to);
	}
  }
  
  return res;
}

signed main(){
  es[0] = {4, N+3, -6831};
  es[1] = {1, N+3, -4583};
  es[2] = {0, N+0, -6592};
  es[3] = {0, N+1, -3063};
  es[4] = {3, N+3, -4975};
  es[5] = {1, N+3, -2049};
  es[6] = {4, N+2, -2104};
  rep((int)R){
	es[i+R] = {es[i].to, es[i].from, es[i].cost};
  }

  printf("%lld\n", kruskal() + 10000 * (N+M));
}
