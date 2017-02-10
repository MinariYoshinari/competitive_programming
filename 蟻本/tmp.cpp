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
//sample data
ll input[8][3] = {
  {0, 1, 100},
  {1, 3, 200},
  {1, 2, 250},
  {2, 3, 100}
};
vector<ll> d, d2, prev;
vector<ll> path;
ll V = 4, E = 8;
priority_queue<P, vector<P>, greater<P> > que;
vector<P> edges[MAX];

void dijkstra(ll start){
  rep(E/2){
	edges[input[i][0]].push_back(P(input[i][1], input[i][2]));
	edges[input[i][1]].push_back(P(input[i][0], input[i][2]));
  }
  
  rep(V){
	d.push_back(INF);
	d2.push_back(INF);
	prev.push_back(INF);
  }
  
  d[start] = 0;
  d2[start] = 0;
  que.push(P(0, start));
  
  while(!que.empty()){
	P v = que.top(); que.pop();
	if(d2[v.second] < v.first) continue; //?
	rep(edges[v.second].size()){
	  P e = edges[v.second][i];
	  ll new_d = d[v.second] + e.second;
	  if(d[e.first] > new_d){
		d2[e.first] = d[e.first];
		d[e.first] = new_d;
		que.push(P(d[e.first], e.first));
	  }else if(d2[e.first] > new_d && d[e.first] != new_d){
		d2[e.first] = new_d;
		que.push(P(d2[e.first], e.first));
	  }
	}

	rep(V){
	  printf("%d: %lld %lld\n", i, d[i], d2[i]);
	}
  }
}
signed main(){
  dijkstra(0);
  printf("%lld\n", d2[V-1]);
  return 0;
}
