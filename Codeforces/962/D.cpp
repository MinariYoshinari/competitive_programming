#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    map<ll, set<int> > mp;
    rep(n) cin >> a[i];
    
    rep(n){
        ll b = a[i];
        while(!mp[b].empty()){
            mp[b].erase(mp[b].begin());
            b *= 2LL;
        }
        mp[b].insert(i);
    }
    
    vector<ll> ans(n, 0LL);
    for(auto itr=mp.begin();itr!=mp.end();++itr){
        for(int idx: itr->second){
            ans[idx] = itr->first;
        }
    }

    int m = 0;
    rep(n) if(ans[i]!= 0) m++;

    cout << m << endl;
    rep(n) if(ans[i] != 0) cout << ans[i] << " ";
    cout << endl;
}
