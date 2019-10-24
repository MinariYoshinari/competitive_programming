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
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int n;
vector<int> edges[100000];
vector<int> fdist(100000, INF);
vector<int> sdist(100000, INF);

int bfs(bool f, bool s, int start, int goal){
    vector<bool> used(n, false);
    queue<Pii> que;
    que.push(Pii(start, 0));
    Pii v;
    while(!que.empty()){
        v = que.front(); que.pop();
        if(f) fdist[v.first] = v.second;
        if(s) sdist[v.first] = v.second;
        used[v.first] = true;
        if(v.first == goal){
            return v.second;
        }
        for(int u : edges[v.first]){
            if(!used[u]){
                que.push(Pii(u, v.second+1));
            }
        }
    }
    return -1;
}

signed main(){
    int a,b;
    cin >> n;
    rep(n-1){
        cin >> a >>b; 
        a--; b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    int dist = bfs(false, false, 0, n-1);
    int f = bfs(true, false, 0, -1);
    int s = bfs(false, true, n-1, -1);
    f = 0;
    s = 0;
    rep(n){
        if(fdist[i] <= sdist[i]){
            f++;
        }else{
            s++;
        }
    }

    if(dist % 2 == 1){
        if(f > s){
            cout << "Fennec";
        }else{
            cout << "Snuke";
        }
    }else{
        if(dist/2+f > dist/2-1+s){
            cout << "Fennec";
        }else{
            cout << "Snuke";
        }
    }
    return 0;
}
