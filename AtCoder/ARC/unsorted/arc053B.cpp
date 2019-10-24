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
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
    string s;
    cin >> s;
    map<char, int> mp;
    rep((int)s.length()){
        mp[s[i]]++;
    }
    int odd = 0, even = 0;
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        even += itr->second / 2;
        if(itr->second % 2 == 1){
            odd++;
        }
    }
    if(odd > 0) cout << 1 + (int)(even/odd) * 2;
    else cout << even*2;
}
