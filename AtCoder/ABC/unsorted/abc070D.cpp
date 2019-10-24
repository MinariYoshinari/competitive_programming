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
#include<numeric>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000
#define INF 9223372036854775807
#define EPS 1e-9
#define DEBUG 0
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

vector< vector<ll> > input(100000, vector<ll>(3));
  vector<ll> d;
  ll V, E;
  priority_queue<Pll, vector<Pll>, greater<Pll> > que;
  vector<Pll> edges[MAX];
  
  void dijkstra(ll start){
    rep(E){
        edges[input[i][0]].push_back(Pll(input[i][1], input[i][2]));
        edges[input[i][1]].push_back(Pll(input[i][0], input[i][2]));
    }

    d.clear();
    rep(V){
        d.push_back(INF);
    }
    d[start] = 0;
    que.push(Pll(0, start));
    
    while(!que.empty()){
        Pll v = que.top(); que.pop();
        if(d[v.second] < v.first) continue; //?
        rep(edges[v.second].size()){
          Pll e = edges[v.second][i];
          if(d[e.first] > d[v.second] + e.second){
              d[e.first] = d[v.second] + e.second;
              que.push(Pll(d[e.first], e.first));
          }
        }
    }
  }
  
  signed main(){
    cin >> V;
    E = V-1;
    rep(E){
        ll a, b, c;
        cin >> a >> b >> c;
        input[i][0] = a-1;
        input[i][1] = b-1;
        input[i][2] = c;
    }

    int Q, K;
    cin >> Q >> K;
    K--;
    dijkstra(K);
    rep(Q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << d[x] + d[y] << endl;
    }
  }