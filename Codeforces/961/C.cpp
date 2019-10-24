#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const double EPS = 1e-9;

int pairs[6][2] = {{0, 1},  {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int board[4][n*n];
    string s;
    rep(4){
        repp(j, n){
            cin >> s;
            repp(k, n){
                board[i][j*n+k] = (s[k] == '1')?1:0;
            }
        }
    }

    vector<ll> a(4, 0LL), b(4, 0LL);
    rep(4){
        repp(j, n*n){
            if(j%2){
                if(board[i][j]){
                    a[i]++;
                }else{
                    b[i]++;
                }
            }else{
                if(board[i][j]){
                    b[i]++;
                }else{
                    a[i]++;
                }
            }
        }
    }

    ll ans = LLONG_MAX;
    rep(6){
        ll tmp = 0LL;
        repp(j, 4){
            if(j == pairs[i][0] || j == pairs[i][1]){
                tmp += a[j];
            }else{
                tmp += b[j];
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
