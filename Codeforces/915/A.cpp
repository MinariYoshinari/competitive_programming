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
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::priority_queue;
using std::stack;
using std::map;
using std::pair;
using std::string;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, k, a, ans = INT_MAX;
    cin >> n >> k;
    rep(n){
        cin >> a;
        if(k % a == 0){
            ans = std::min(ans, k/a);
        }
    }
    cout << ans << endl;

}
