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
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,c;
    cin >> n >> c;
    vector<int> vl(n);
    rep(n){
        cin >> vl[i];
    }
    sort(all(vl));

    int ans = 0, check = n-1;
    rep(n){
        while(check >= 0 && vl[i] + vl[check] + 1 > c){
            check--;
        }
        if(check >= 0){
            vl[check] = INF;
            check--;
            ans++;
        }else if(vl[i] <= c){
            ans++;
        }
        //cout << check << " " << ans << endl;
    }
    cout << ans;
}
