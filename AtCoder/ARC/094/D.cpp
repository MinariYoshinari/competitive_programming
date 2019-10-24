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
        if(a > b) swap(a,b);

        ll ans = 0, aa = 1, bb = a*b-1;
        while(aa < bb){
            debug(aa); debug(bb);
            if(aa != a) ans++;
            if(bb != b) ans++;
            while((a*b)/++aa == bb);
            bb = (a*b)/aa;
            if(bb == b || aa*bb == a*b) bb--;
        }
        debug(aa); debug(bb);
        if(aa == bb && aa*bb != a*b) ans++;

        cout << ans << endl;
    }
}
