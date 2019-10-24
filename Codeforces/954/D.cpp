#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

map<ll, ll> d;
priority_queue< Pll, vector<Pll>, greater<Pll> > que;
map<ll, vector<Pll> > edges;

void dijkstra(ll start){
    d[start] = 0;
    que.push(Pll(0, start));

    while(!que.empty()){
        Pll v = que.top(); que.pop();
        if(d.find(v.second) != d.end() && d[v.second] < v.first) continue;
        for(Pll e: edges[v.second]){
            if(d.find(e.first) == d.end() || d[e.first] > d[v.second] + e.second){
                d[e.first] = d[v.second] + e.second;
                que.push(Pll(d[e.first], e.first));
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,s,t,a,b;
    cin >> n >> m;
    cin >> s >> t;
    rep((int)m){
        cin >> a >> b;
        edges[a].emplace_back(b, 1);
        edges[b].emplace_back(a, 1);
    }
    dijkstra(s);
    cout << n*(n-1)/2 - d[t]*(d[t]-1)/2 - m << endl; 
}
