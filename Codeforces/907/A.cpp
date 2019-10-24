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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> v(4), ans(3);
    rep(4) cin >> v[i];
    ans[0] = v[0]*2;
    // ans[1] = min(v[0]-1, v[1]*2);
    ans[1] = v[1] * 2;
    ans[2] = min(v[2], v[3]) * 2;
    // ans[2] = min(min(v[1]-1, v[2]*2), v[3]*2);
    int flag = 1;
    rep(3) if(v[i] > ans[i]) flag = 0;
    if(v[3]*2 >= ans[0] || v[3]*2 >= ans[1] || v[3]*2 < ans[2] || v[3] > ans[2]){
        flag = 0;
    }
    if(flag){
        rep(3) cout << ans[i] << endl;
    }else{
        cout << -1 << endl;
    }
}
