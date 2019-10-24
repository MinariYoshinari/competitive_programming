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

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(ll j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

ll ok[36][36];
ll a,b;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

ll solve(ll num, vector<int> used){
    if(num >= a){
        used[num-a] = 1;
        rep(num-a){
            if(used[i] && !ok[i][num-a]) return 0;
        }
    }

    ll ret = 1; // 数字なしのぶん
    reppp(i, num+1, b){
        ret += solve(i, used);
    }
    /*
    printf("solve(%lld, ", num);
    rep(b-a+1){
        printf("%d", used[i]);
    }
    printf(") = %lld\n", ret);
    */
    return ret;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;

    reppp(i, a+1, b){
        reppp(j, a, i-1){
            if(gcd(i,j) == 1){
                ok[j-a][i-a] = 1;
            }else{
                ok[j-a][i-a] = 0;
            }
        }
    }

    cout << solve(a-1, vector<int>(b-a+1, 0)) << endl;
}
