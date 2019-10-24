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
#define INF 3e13
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

vector<ll> d;
ll V, E;
vector<edge> edges;

bool bellman_ford(ll start){
  rep(V){
	  d.push_back(INF);
  }
  d[start] = 0;

  ll cnt = E+1, cost_tmp = 0;
  bool update = true;
  while(update){
	update = false;
	  rep(E){
	    edge e = edges[i];
	    if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
		    d[e.to] = d[e.from] + e.cost;
		    update = true;
	    }
	  }
	  cnt--;
	  if(cnt == 0){
		 cost_tmp = d[V-1];
	  }else if(cnt == -E-1){
		  if(d[V-1] < cost_tmp){
			  return true;
		  }else{
			  break;
		  }
	  }
  }
  return false;
}



signed main(){
	cin >> V >> E;
	rep(E){
		edge e;
		cin >> e.from >> e.to >> e.cost;
		e.from--; e.to--;
		e.cost *= -1;
		edges.push_back(e);
	}
	bool flag = bellman_ford(0);
	if(flag){
		cout << "inf";
	}else{
		cout << -d[V-1];
	}
}
