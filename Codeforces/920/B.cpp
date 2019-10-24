#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cassert>
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
    int t;
    cin >> t;
    repp(j, t){
        int n;
        cin >> n;
        int l, r, ans[n], s = 1;
        rep(n){
            cin >> l >> r;
            if(s <= r){
                ans[i] = max(s, l);
                s = ans[i]+1;
            }else{
                ans[i] = 0;
            }
        }

        rep(n-1) cout << ans[i] << " ";
        cout << ans[n-1] << endl;
    }
    return 0;
}
