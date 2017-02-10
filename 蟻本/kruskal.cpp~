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

ll cost[MAX][MAX];
ll mincost[MAX];
priority_queue<P, vector<P>, greater<P> > que;
bool used[MAX];
int V = 7;

ll prim(){
  fill(mincost, mincost+V, INF);
  fill(used, used+V, false);
  que.push(make_pair(0, 0));
  int res = 0;

  while(true){
	P v;
	while(!que.empty()){
	  if(!used[que.top().second]){
		v = que.top();
		break;
	  }
	  que.pop();
	}

	if(que.empty()) break;
	used[v.second] = true;
	res += v.first;

	rep(V){
	  mincost[i] = min(mincost[i], cost[v.second][i]);
	  que.push(make_pair(mincost[i], i));
	}
  }
  
  return res;
}

signed main(){
  fill(cost[0], cost[V], INF);
  cost[0][2] = cost[2][0] = 1;
  cost[1][2] = cost[2][1] = 2;
  cost[2][3] = cost[3][2] = 3;
  cost[1][4] = cost[4][1] =10;
  cost[2][5] = cost[5][2] = 7;
  cost[4][5] = cost[5][4] = 5;
  cost[3][6] = cost[6][3] = 5;
  cost[5][6] = cost[6][5] = 8;
  cost[3][5] = cost[5][3] = 1;

  printf("%lld\n", prim());
}
