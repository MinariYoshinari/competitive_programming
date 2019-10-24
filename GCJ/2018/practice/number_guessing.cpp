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

    rep(t){
        int a,b,n;
        cin >> a >> b;
        cin >> n;

        int ng = a, ok = b, mid;
        string s;
        repp(j, n){
            mid = (ng+ok)/2;
            if(ng == mid) mid++;
            cout << mid << endl;
            cin >> s;

            // TOO_SMALL
            if(s[4] == 'S'){
                ng = mid;
            // TOO_BIG
            }else if(s[4] == 'B'){
                ok = mid;
            // WRONG_ANSWER
            }else if(s[4] == 'G'){
                exit(0);
            }else{
                break;
            }
        }
    }
}
