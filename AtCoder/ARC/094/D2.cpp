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

int main(){
    int q;
    cin >> q;
    repp(qq, q){
        ll a,b;
        cin >> a >> b;

        ll ans = 0;
        ll aa = (ll)sqrt((double)(a*b));
        if(aa * aa == a*b) aa--;
        ans += 2 * aa;
        if(aa != 0 && aa == (a*b-1)/aa) ans--;
        if(aa >= min(a,b)) ans--;  

        cout << ans << endl;
    }
}
