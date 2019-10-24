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

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> v;
    int mincnt = m;
    string s,t;
    cin >> s >> t;
    rep(m-n+1){
        int cnt = 0;
        vector<int> tmpv(n);
        repp(j, n){
            if(s[j] != t[i+j]){
                cnt += 1;
                tmpv[j] = 1;
            }else{
                tmpv[j] = 0;
            }
        }
        if(cnt < mincnt){
            mincnt = cnt;
            v.clear();
            rep(n) if(tmpv[i] == 1) v.pb(i+1);
        }
    }
    cout << mincnt << endl;
    if(mincnt == 0) return 0;
    rep(mincnt-1){
        cout << v[i] << " ";
    }
    cout << v.back();
    return 0;
}