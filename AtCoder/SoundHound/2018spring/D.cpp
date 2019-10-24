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
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int h,w;
    cin >> h >> w;
    vector< vector<int> > p(h, vector<int>(h)), f(h, vector<int>(h));
    rep(h) repp(j, w) cin >> p[i][j];
    rep(h) repp(j, w){
        cin >> f[i][j];
        p[i][j] -= f[i][j];
    }

    priority_queue< pair<int, vector< vector<int> > > > que;
    vector< vector<int> > pp(p);
    pp[0][0] -= p[0][0];
    que.push(pair<int, vector< vector<int> >> >(p[i][j], pp));
    while(!que.empty()){
        pair<int, vector< vector<int> > > pt = que.top(); que.pop();
        
    }

}
