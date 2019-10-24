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
#define DEBUG 0
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

vector<int> es[100001];
vector<double> p(100001);
vector<double> dist;
double ans = 0.0;

void bfs(int n){
    queue<Pii> que;
    vector<int> use(n, 0);
    que.push(Pii(0, 0));
    p[0] = 1.0;
    while(!que.empty()){
        Pii t = que.front(); que.pop();
        use[t.first] = 1;
        int cnt = 0;
        for(int next : es[t.first]){
            if(!use[next])cnt++;
        }
        for(int next : es[t.first]){
            p[next] = p[t.first] / cnt;
            if(!use[next]){
                que.push(Pii(next, t.second + 1));
                cnt++;
            }
        }
        if(cnt > 0){
            ans += (double)t.second * p[t.first];
        }
    }
}

signed main(){
    int n;
    cin >> n;
    rep(n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        es[a].pb(b);
        es[b].pb(a);
    }
    bfs(n);

    printf("%.9lf", ans);
}
