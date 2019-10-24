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
#define MAX 1001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

vector<Pii> pairs(MAX, Pii(0, 0));
vector<int> es[MAX], xs(MAX), colors(MAX);

bool dfs(int node){
    bool ret = true;
    Pii sum_pair = Pii(0, 0);
    for(int next: es[node]){
        ret &= dfs(next);
        sum_pair.first += pairs[next].first;
        sum_pair.second += pairs[next].second;
    }
    if(es[node].empty()){
        pairs[node] = Pii(xs[node], 0);
        color[node] = 1;
    }else{
        if(sum_pair.first <= xs[node]){
            pairs[node] = Pii(xs[node], sum_pair.second);
            colors[node] = 1;
        }else if(sum_pair.second <= xs[node]){
            pairs[node] = Pii(sum_pair.first, xs[node]);
            colors[node] = 2;
        }else{
            ret = false;
        }
    }
    //cout << node << " "  << color << " " << ret << endl;
    return ret;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    if(n == 1){
        cout << "POSSIBLE";
        return 0;
    }
    reppp(i, 1, n-1){
        int par;
        cin >> par;
        es[par-1].pb(i);
    }
    rep(n) cin >> xs[i];

    if(dfs(0)){
        cout << "POSSIBLE";
    }else{
        cout << "IMPOSSIBLE";
    }
    return 0;
}