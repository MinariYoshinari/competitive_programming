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

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(ll j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<=n;i++)
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


signed main(){
    int n, tmp;
    cin >> n;
    vector<int> es[n], numOfChildren(n, 0);
    rep(n){
        cin >> tmp;
        tmp--;
        es[tmp].pb(i);
        numOfChildren[tmp]++;
    }

    vector<int> g(n, MAX);
    rep(n){
        auto iter = min_element(all(numOfChildren));
        int idx = (int)(iter - numOfChildren.begin());
        cout << idx << endl;
        int num = 0;
        for(int j : es[idx]){
            if(g[j] != MAX){
                if(num == g[j]){
                    num = g[j] + 1;
                }
            }
        }
        g[idx] = num;
        numOfChildren[idx] = MAX;
    }

    bool flag = true;

    rep(n){
        cout << g[i];
    }
    cout << endl;

    rep(n){
        vector<int> check(g[i], 0);
        for(int j : es[i]){
            if(g[j] < g[i]) check[g[j]] = 1;
        }
        repp(j, g[i]){
            if(check[j] == 0){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    if(flag){
        cout << "POSSIBLE";
    }else{
        cout << "IMPOSSIBLE";
    }
    
}