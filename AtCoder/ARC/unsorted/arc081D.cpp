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
#define DEBUG 0
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

//'z' - 'A'で57

vector<int> a[58];

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    /*
    repp(j, n){
        if(s[0][j] == s[1][j]) continue;
        a[(int)(s[0][j] - 'A')].pb((int)(s[1][j] - 'A'));
        a[(int)(s[1][j] - 'A')].pb((int)(s[0][j] - 'A'));
    }
    rep(2){
        repp(j, n-1){
            if(s[i][j] != s[i][j+1]){
                a[(int)(s[i][j] - 'A')].pb((int)(s[i][j+1] - 'A'));
            }
        }
    }*/


    ll ans;
    int i;
    if(s[0][0] == s[1][0]){
        ans = 3;
        i = 1;
    }else{
        ans = 6;
        i = 2;
    }
    while(i < n){
        if(s[0][i] == s[1][i]){
            if(s[0][i-1] == s[1][i-1]){
                ans *= 2;
            }else{
                ans *= 1;
            }
            i += 1;
        }else{
            if(s[0][i-1] == s[1][i-1]){
                ans *= 2;
            }else{
                ans *= 3;
            }
            i += 2;
        }
        ans %= MOD;
    }

    cout << ans;
  
}
