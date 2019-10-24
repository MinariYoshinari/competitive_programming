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
    int n;
    cin >> n;
    vector<long double> x(n), y(n);
    rep(n){
        cin >> x[i] >> y[i];
    }

    rep(n){
        long double ans = 1e16;
        repp(j, n){
            if(i == j) continue;
            long double a,b,f;
            a = x[j]*2 - x[i]*2;
            b = y[j]*2 - y[i]*2;
            f = a*x[i]+b*y[i] + x[i]*x[i] + y[i]*y[i] - x[j]*x[j] - y[j]*y[j];
            reppp(k, j+1, n){
                if(i == k) continue;
                long double c,d,g;
                c = x[k]*2 - x[i]*2;
                d = y[k]*2 - y[i]*2;
                g = c*x[i]+d*y[i] + x[i]*x[i] + y[i]*y[i] - x[k]*x[k] - y[k]*y[k];
                cerr << abs(atan((a*d-b*c)/(a*c+b*d))) * 0.5 / M_PI << " ";
                ans = min(ans, abs(atan((a*d-b*c)/(a*c+b*d))) * 0.5 / M_PI);
            }
        }
        cout << ans << endl;
    }
}
