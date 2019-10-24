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
#define MAX 100000
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

//int G[MAX][MAX];
vector<int> G[MAX], colors(MAX, -1);


int bfs_colors(){
    queue<Pii> que;
    que.push(Pii(0, 0));
    while(!que.empty()){
        Pii p = que.front(); que.pop();
        if(colors[p.first] != -1){
            if(colors[p.first] != p.second){
                return 1;
            }else{
                continue;
            }
        }
        colors[p.first] = p.second;
        for(int next: G[p.first]){
            que.push(Pii(next, 1-p.second));
        }
    }
    return 0;
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, from, to;
    cin >> n >> m;
    rep(m){
        cin >> from >> to;
        from--; to--;
        G[from].pb(to);
        G[to].pb(from);
    }

    int loop_flag = bfs_colors();
    if(loop_flag){
        cout << (ll)n * (ll)(n-1) / 2 - (ll)m;
    }else{
        ll red = count(all(colors), 0);
        ll black = (ll)n - red;
        cout << red * black - (ll)m;
    }
    return 0;
}
