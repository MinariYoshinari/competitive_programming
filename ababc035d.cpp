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

#define rep(n) for(unsigned int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define MAX 10000
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{ll from, to, cost;};

ll input[MAX][3];
vector<ll> d, prev;
vector<ll> path;
ll V, E, T;
priority_queue<P, vector<P>, greater<P> > que;
vector<P> edges[MAX];

void dijkstra(ll start){
  rep(E/2){
	edges[input[i][0]].push_back(P(input[i][1], input[i][2]));
	edges[input[i][1]].push_back(P(input[i][0], input[i][2]));
  }
  
  rep(V){
	d.push_back(INF);
	prev.push_back(INF);
  }
  d[start] = 0;
  que.push(P(0, start));
  
  while(!que.empty()){
	P v = que.top(); que.pop();
	if(d[v.second] < v.first) continue;
	rep(edges[v.second].size()){
	  P e = edges[v.second][i];
	  if(d[e.first] > d[v.second] + e.second){
		d[e.first] = d[v.second] + e.second;
		que.push(P(d[e.first], e.first));
	  }
	}
  }
}

signed main(){
	scanf("%d %d %d", &V, &E, &T);
	E *= 2;
	int max_gain_town = -1, max_gain = 0, gain = 0;
	rep(V){
		scanf("%d", gain);
		if(max_gain < gain){
			max_gain = gain;
			max_gain_town = i;
		}
	}
	rep(E/2){
		//scanf("%d ")
		//ここから
	}

  dijkstra(0);
  printf("%lld\n", d[V-1]);

  printf("shortest path: ");
  for(int i=path.size()-1;i>=0;i--){
	printf("%lld ", path[i]);
  }
  printf("\n");
}
