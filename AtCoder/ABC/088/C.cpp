#include <bits/stdc++.h>

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
    int a[3], b[3], c[3][3];
    rep(3) repp(j, 3) cin >> c[i][j];
    rep(3) b[i] = c[0][i];
    rep(3) a[i] = c[i][0] - c[0][0];

    rep(3) repp(j, 3){
        if(a[i] + b[j] != c[i][j]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
