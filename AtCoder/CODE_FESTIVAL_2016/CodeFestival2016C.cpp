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
#define MAX 100001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

vector<int> es[2 * MAX];
vector<int> use(2 * MAX, 0);

void bfs(int start){
    int node;
    queue<int> q;
    q.push(start);
    use[start] = 1;

    while(!q.empty()){
        node = q.front(); q.pop();
        for(int next: es[node]){
            if(use[next] == 0){
                q.push(next);
                use[next] = 1;
            }
        }
    }
}

signed main(){
    int n, m, k, tmp;
    cin >> n >> m;

    rep(n){
        cin >> k;
        repp(j, k){
            cin >> tmp;
            es[i].pb(tmp+MAX);
            es[tmp+MAX].pb(i);
        }
    }

    bfs(0);

    int flag = 1;
    rep(n){
        if(use[i] == 0){
            flag = 0;
            break;
        }
    }

    if(flag == 1){
        cout << "YES";
    }else{
        cout << "NO";
    }

}
