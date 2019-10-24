#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string march = "MARCH", s;
    vector<ll> cnt(5, 0LL);
    rep(n){
        cin >> s;
        repp(j, 5){
            if(s[0] == march[j]){
                cnt[j]++;
                break;
            }
        }
    }

    ll ans = 0LL;
    rep(3){
        reppp(j, i+1, 4){
            reppp(k, j+1, 5){
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << endl;
}
