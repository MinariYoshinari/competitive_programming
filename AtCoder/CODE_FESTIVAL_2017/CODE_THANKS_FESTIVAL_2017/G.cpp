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
    
#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
    
using namespace std;
struct edge{int from, to; ll cost;};
    
vector<int> G[40];
vector<int> c(40,-1);
    
void dfs(int start, int node, int color){
    c[node] = color;
    for(int next: G[node]){
        if(c[next] == -1){
            dfs(start, next, 1-color);
        }else if(c[next] == color){
            c[next] = -2;
            return;
        }
    }
    return;
}

bool negative(int n){
    return n<0;
}
    
signed main(){
    int n, m, from, to;
    cin >> n >> m;
    if(m == 0){
        cout << n << endl;
        return 0;
    }
    rep(m){
        cin >> from >> to;
        G[from-1].push_back(to-1);
        G[to-1].push_back(from-1);
    }

    int ans = 0;
    rep(n){
        if(c[i] != -1) continue;
        vector<int> cc(c);
        dfs(i, i, 1);
        int count1 = count(all(c),1);
        c = cc;
        dfs(i, i, 0);
        if(count1 > count(all(c), 1)){
            c = cc;
            dfs(i, i, 1);
        }
        // repp(j,n){
        //     cout << c[j] << " ";
        // }
        // cout << endl;
        // repp(j,n){
        //     cout << c[j] << " ";
        // }
        // cout << endl;
    }
    int count2 = count(all(c), -2);
    int count1  = count(all(c), 1);
    ans = max(max(ans, count1), n-count2-count1);
    cout << ans << endl;
    return 0;
}

// 0 -1 0 -1 1 0 0 1 1 1 1 0 0 1 1 1 0 -1 -1 0
// 0  1 0  1 1 0 0 1 1 1 1 0 0 1 1 1 0  1  0 0
