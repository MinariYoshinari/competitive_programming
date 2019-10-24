#include <bits/stdc++.h>

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(ll j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    ll n = (ll)s.length();
    
    ll ans = 0;
    repp(i, 1LL << (n-1)){
        int start = 0;
        repp(j, n){
            if(i & (1LL << j)){
                ans += stoll(s.substr(start, j-start+1));
                start = j+1;
            }
        }
        ans += stoll(s.substr(start, n-1-start+1));
    }
    cout << ans << endl;
}
