#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<bitset>

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

    int A,B;
    cin >> A >> B;
    int d[A+1][B+1], f[101][101], dmax = 0;
    reppp(i, 1, A+1) reppp(j, 1, B+1){
        cin >> d[i][j];
        dmax = max(dmax, d[i][j]);
    }

    repp(a, dmax+1) repp(b, dmax+1){
        int m = 0;
        reppp(x, 1, A+1) reppp(y, 1, B+1){
            m = max(m, d[x][y] - x*a - y*b);
        }
        f[a][b] = max(0, m);
    }

    reppp(x, 1, A+1) reppp(y, 1, B+1){
        int shortest = INT_MAX;
        repp(a, dmax+1) repp(b, dmax+1){
            shortest = min(shortest, x*a + y*b + f[a][b]);
        }
        if(d[x][y] != shortest){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    printf("Possible\n%d %d\n", (dmax+1)*2, (dmax+1)*(dmax+1) + 2*dmax);
    reppp(n, 1, dmax+1) printf("%d %d X\n", n, n+1);
    reppp(n, dmax+2, 2*dmax+2) printf("%d %d Y\n", n, n+1);
    repp(a, dmax+1) repp(b, dmax+1) printf("%d %d %d\n", a+1, 2*dmax+2-b, f[a][b]);
    printf("1 %d\n", 2*dmax+2);
    return 0;
}
