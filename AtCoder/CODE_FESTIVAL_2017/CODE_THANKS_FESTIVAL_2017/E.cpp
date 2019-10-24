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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
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

signed main(){

    int n, w;
    cin >> n;

    string ans = "!";
    int j = 0;
    while(j < n){
        string s = "?";
        repp(jj, j) s += " 0";
        int num = 1, base = 0;
        reppp(jj, j, min(j+4, n-1)){
            s += " " + to_string(num);
            base += 8 * num;
            num *= 5;
        }
        reppp(jj, j+5, n-1) s += " 0";
        cout << s << endl;

        cin >> w;
        w -= base;
        reppp(jj, j, min(j+4, n-1)){
            ans += " " + to_string((w%5) % 2);
            w /= 5;
        }

        j += 5;
    }

    cout << ans << endl;

}
