#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cassert>
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
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, m, from, to;
    cin >> n >> m;
    vector<int> deg(n, 0);
    rep(m){
        cin >> from >> to;
        deg[from-1]++;
        deg[to-1]++;
    }
    sort(rall(deg));
    if(deg.back() == 0){
        cout << n << endl;
        return 0;
    }
    vector<int> ans;
    int cnt = 0, g = n-1, rest = n;
    rep(n){
        if(deg[i] >= g) cnt++;
        else g = deg[i];
        if(cnt == n-g){
            ans.push_back(n-g);
            rest -= cnt;
            cnt = 0;
        }
    }
    if(rest > 0) ans.push_back(rest);

    cout << ans.size() << endl;
    sort(all(ans));
    for(int x: ans){
        cout << x <<  " ";
    }
    cout << endl;
    return 0;
}