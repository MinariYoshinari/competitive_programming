#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<bitset>

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
typedef pair<Pii, int> Piii;
struct edge{int from, to; ll cost;};

vector<Pll> G[100000];
ll pos[100000];
int used[100000];

int dfs(ll node){
    for(Pll next: G[node]){
        if(pos[next.first] != LLONG_MAX && pos[next.first] != pos[node] + next.second){
            return 0;
        }else if(!used[next.first]){
            pos[next.first] = pos[node] + next.second;
            used[next.first] = 1;
            if(!dfs(next.first)) return 0;
        }
    }
    return 1;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n,m; ll l,r,d;
    cin >> n >> m;
    if(m == 0){
        cout << "Yes" << endl;
        return 0;
    }

    set<ll> nodes;
    rep(m){
        cin >> l >> r >> d;
        l--; r--;
        G[l].emplace_back(r, d);
        G[r].emplace_back(l, -d);
        if(nodes.find(l) == nodes.end() && nodes.find(r) == nodes.end()) nodes.insert(l);
    }

    fill(pos, pos+n, LLONG_MAX);
    int used[n];
    rep(n){
        used[i] = 1;
        if(pos[i] == LLONG_MAX) pos[i] = 0;
        if(!dfs(i)){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
