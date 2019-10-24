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
    int n, s;
    cin >> n;
    vector<int> a(n);
    rep(n) cin >> a[i];
    s = accumulate(all(a), 0);
    bitset<4000001> bs(0LL);

    bs.set(0);
    rep(n){
        bitset<4000001> bs2(bs);
        bs2 <<= a[i];
        bs |= bs2;
    }
    reppp(i, (s+1)/2, s+1){
        if(bs[i]){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
