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

string s;
int l;

ll solve(){
    vector<ll> v[5000];
    int d = 0, i = 0;
    while(i < l){
        if(s[i] == '['){
            d++;
            v[d].clear();
            i++;
        }else if(s[i] == ']'){
            int m = ((int)v[d].size() + 1) >> 1;
            ll total = 0;
            sort(all(v[d]));
            repp(j, m){
                total += v[d][j];
            }
            d--;
            v[d].push_back(total);
            i++;
        }else{
            int nl = 1;
            while(s[i+nl] != '[' && s[i+nl] != ']') nl++;
            v[d].emplace_back( (stoi(s.substr(i, nl)) + 1) >> 1 );
            i += nl;
        }
    }
    // rep(3){
    //     for(ll x: v[i]) cout << x << " ";
    //     cout << endl;
    // }
    // assert((int)v[0].size() == 1);
    return v[0][0];
}

int main(){
    int n;
    cin >> n;
    rep(n){
        cin >> s;
        l = (int)s.length();
        cout << solve() << endl;
    }
}
