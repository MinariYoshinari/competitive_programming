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
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{ll from, to, cost;};

//compile command -> g++ -Wall bellman_ford.cpp -std=c++11


//sample data
ll input[10][3] = {
  {0, 1, 2},
  {0, 2, 5},
  {1, 2, 4},
  {1, 3, 6},
  {1, 4,10},
  {2, 3, 2},
  {3, 5, 1},
  {4, 6, 5},
  {4, 5, 3},
  {5, 6, 9}
};
vector<ll> d;
ll V = 7, E = 20;
vector<edge> edges;

void bellman_ford(ll start){
  rep(E){
	edge e;
	e.from = input[i][0]; e.to = input[i][1]; e.cost = input[i][2];
	edges.push_back(e);
	swap(e.from, e.to);
	edges.push_back(e);
  }
  
  rep(V){
	d.push_back(INF);
  }
  d[start] = 0;
  
  bool update = true;
  while(update){
	update = false;
	rep(E){
	  edge e = edges[i];
	  if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
		d[e.to] = d[e.from] + e.cost;
		printf("d[%lld] = %lld\n", e.to, d[e.to]);
		update = true;
	  }
	}
  }
}



signed main(){
  bellman_ford(0);
  printf("%lld\n", d[V-1]);
}
