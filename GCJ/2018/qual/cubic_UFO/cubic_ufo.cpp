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
const double EPS = 1e-12;

double points[3][3] = {
            {0.5, 0, 0},
            {0, 0.5, 0},
            {0, 0, 0.5}
        };

int main(){
    int t;
    double a;
    scanf("%d", &t);
    repp(tt, t){
        scanf("%lf", &a);
        double theta = asin(a/1.414213-EPS) - M_PI_4;
        rep(3){
            double x = points[i][0] * cos(theta) - points[i][1] * sin(theta);
            double y = points[i][0] * sin(theta) + points[i][1] * cos(theta);
            printf("%.16lf %.16lf %.16lf\n", x, y, points[i][2]);
        }
    }
}