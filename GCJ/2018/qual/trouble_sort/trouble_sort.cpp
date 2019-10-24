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

int main(){
    int t;
    cin >> t;
    reppp(tt, 1, t+1){
        cout << "Case #" << tt << ": ";

        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp[2];
        rep(n){
            cin >> v[i];
            mp[i%2][v[i]]++;
        }

        vector<int> u(v);
        sort(all(u));
        int ok = 1;
        rep(n){
            if(!mp[i & 1][u[i]]){
                ok = 0;
                cout << i << endl;
                break;
            }
            mp[i&1][u[i]]--;
        }
        if(ok){
            cout << "OK" << endl;
        }
    }
}