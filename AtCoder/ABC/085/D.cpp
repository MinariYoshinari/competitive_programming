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
    ios::sync_with_stdio(0); cin.tie(0);
    int n,h, ans = 0;
    cin >> n >> h;
    vector<int> a(n), b(n);
    rep(n) cin >> a[i] >> b[i];
    sort(rall(b));

    int d = *max_element(all(a));
    rep(n){
        if(h <= 0 || d > b[i]) break;
        h -= b[i];
        ans++;
    }
    if(h > 0){
        ans += (h+d-1)/d;
    }
    cout << ans << endl;
    return 0;
}
