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
    int n;
    cin >> n;
    unsigned long a;
    bitset<32> aa = 0;
    vector<unsigned long> vb;
    rep(n){
        cin >> a;
        aa ^= bitset<32>(a);
        vb.push_back(a^(a-1));
    }
    sort(rall(vb));
    unique(all(vb));
    int i = 31, ans = 0;
    for(auto bb_n : vb){
        bitset<32> bb = bitset<32>(bb_n);
        // cout << aa << endl;
        while(i >= 0 && !aa.test(i)) i--;
        if(i == -1) break;
        if(aa.test(i) && bb.test(i) && !bb.test(i+1)){
            aa ^= bb;
            ans++;
        }
    }
    if(aa.any()) ans = -1;
    cout << ans << endl;
    return 0;
}

