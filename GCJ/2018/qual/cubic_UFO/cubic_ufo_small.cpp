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
const long double EPS = 1e-7;

long double points[3][3] = {
            {0.5, 0, 0},
            {0, 0.5, 0},
            {0, 0, 0.5}
        };

int main(){
    int t;
    long double a;
    cin >> t;
    repp(tt, t){
        cin >> a;

        printf("Case #%d:\n", tt+1);
        long double theta = (abs(a-1.0) < EPS)?0.0:M_PI_4;
        rep(3){
            long double x = points[i][0] * cos(theta) - points[i][1] * sin(theta);
            long double y = points[i][0] * sin(theta) + points[i][1] * cos(theta);
            printf("%.16Lf %.16Lf %.16Lf\n", x, y, points[i][2]);
        }
    }
}