#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

map<ll, ll> d;
int flag[2500];
priority_queue< Pll, vector<Pll>, greater<Pll> > que;
map<ll, vector<Pll> > edges;

void dijkstra(ll start){
    d[start] = 0;
    que.push(Pll(0, start));

    while(!que.empty()){
        Pll v = que.top(); que.pop();
        if(d.find(v.second) != d.end() && d[v.second] < v.first) continue;
        rep(edges[v.second].size()){
            Pll e = edges[v.second][i];
            if(d.find(e.first) == d.end() || d[e.first] > d[v.second] + e.second){
                d[e.first] = d[v.second] + e.second;
                flag[e.first] = 1;
                que.push(Pll(d[e.first], e.first));
            }
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int h,w;
    cin >> h >> w;
    
    string field[h];
    int sharp = 0;
    rep(h){
        cin >> field[i];
        repp(j, w){
            if(field[i][j] == '#'){
                sharp++;
                continue;
            }
        }
    }

    rep(h)repp(j, w){
        if(j != 0 && field[i][j-1] == '.'){
            edges[w*i+j-1].emplace_back(w*i+j, 1);
            edges[w*i+j].emplace_back(w*i+j-1, 1);
        }
        if(i != 0 && field[i-1][j] == '.'){
            edges[w*(i-1)+j].emplace_back(w*i+j, 1);
            edges[w*i+j].emplace_back(w*(i-1)+j, 1);
        }
    }
    dijkstra(0);
    if(flag[w*h-1]) cout << h*w - d[w*h-1] - 1 - sharp << endl;
    else cout << -1 << endl;

}
