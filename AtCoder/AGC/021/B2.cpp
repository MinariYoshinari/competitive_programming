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

long double R = 1e6;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<long double> x(n), y(n), cnt(n, 0);
    rep(n){
        cin >> x[i] >> y[i];
    }

    rep(2*(int)R){
        long double xs = cos(((long double)i / (2.0*R)) * 2.0 * M_PI);
        long double ys = sin(((long double)i / (2.0*R)) * 2.0 * M_PI);
        long double mindist = 1e20;
        int mindist_point;
        repp(j, n){
            // long double d = x[j]*x[j] + y[j]*y[j] - 2*R*(xs*x[j]+ys*y[j]) + R*R;
            long double d = -xs*x[j]-ys*y[j];
            if(mindist > d){
                mindist = d;
                mindist_point = j;
            }
        }
        cnt[mindist_point] += 1.0;
    }
    rep(n){
        cnt[i] /= 2.0*R;
        printf("%.6Lf\n", cnt[i]);
    }
}
