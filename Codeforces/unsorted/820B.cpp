#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int n,a;
    cin >> n >> a;
    double sumd  = 180.0 * (double)(n-2), d = sumd/(double)n;
    double deg = (180.0 - d) / 2.0;
    if(n == 3){
        printf("1 2 3");
        return 0;
    }

    /*
    double dntmp = (double)(int)((double)d / deg);
    int dn = dntmp;
    if(dn > 1 && abs((double)a - deg * (double)(dn-1)) < abs((double)a - deg * (double)dn)) dn = dntmp - 1;
    if(dn < n && abs((double)a - deg * (double)(dn+1)) < abs((double)a - deg * (double)dn)) dn = dntmp + 1;
    */
    int dn = 3, mindn = 3;
    double mindiff = 100001;
    while(dn <= n){
        if(abs((double)a - deg * (double)(dn-2)) < mindiff){
            mindiff = abs((double)a - deg * (double)(dn-2));
            mindn = dn;
        }
        dn++;
    }
    if(mindn > n) mindn = n;
    printf("2 1 %d", mindn);
    return 0;
}

// whileの方がforより速い説