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
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, pos, l, r, ans = 0, pos2, ans2= 0;
    cin >> n >> pos >> l >> r;
    pos2 = pos;

    if(l != 1){
        ans += abs(pos-l) + 1;
        pos = l;
    }
    
    if(r != n){
        ans += abs(r-pos) + 1;
        ans2 += abs(r-pos2) + 1;
        pos2 = r;
    }

    if(l != 1)
        ans2 += abs(pos2-l) + 1;
        
    cout << min(ans, ans2) << endl;
    return 0;
}
