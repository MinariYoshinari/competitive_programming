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
#define MAX 100000000000
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{ll from, to; ll cost;};

vector<edge> input;
map<ll, ll> d;
priority_queue< Pll, vector<Pll>, greater<Pll> > que;
map<ll, vector<Pll> > edges;

void dijkstra(ll start){
    d[start] = 0;
    que.push(Pll(0, start));

    while(!que.empty()){
        Pll v = que.top(); que.pop();
        if(d.find(v.second) != d.end() && d[v.second] < v.first) continue;
        if(edges.find(v.second) != edges.end())rep(edges[v.second].size()){
            Pll e = edges[v.second][i];
            if(d.find(e.first) == d.end() || d[e.first] > d[v.second] + e.second){
                d[e.first] = d[v.second] + e.second;
                que.push(Pll(d[e.first], e.first));
            }
        }
    }

}

signed main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll p,q,c;
    rep(m){
        cin >> p >> q >> c;
        p--; q--;
        edges[p*(m+1)+c].eb(q*(m+1)+c, 0);
        edges[q*(m+1)+c].eb(p*(m+1)+c, 0);
        edges[p*(m+1)+c].eb(p*(m+1), 0);
        edges[p*(m+1)].eb(p*(m+1)+c, 1);
        edges[q*(m+1)+c].eb(q*(m+1), 0);
        edges[q*(m+1)].eb(q*(m+1)+c, 1);
    }

    dijkstra(0);
    if(d.find((n-1)*(m+1)) != d.end()){
        printf("%lld\n", d[(n-1)*(m+1)]);
    }else{
        printf("-1\n");
    }
}

