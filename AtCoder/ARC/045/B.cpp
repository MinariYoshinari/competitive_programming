#include <bits/stdc++.h>

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

    int n,m;
    cin >> n >> m;
    vector<int> imos(n, 0), dissaborable(n, 0), ans;
    vector<Pii> p(m);
    rep(m){
        cin >> p[i].first >> p[i].second;
        p[i].first--;
        imos[p[i].first]++;
        imos[p[i].second]--;
    }
    dissaborable[0] = (int)(imos[0] == 1);
    reppp(i, 1, n){
        imos[i] += imos[i-1];
        dissaborable[i] = (int)(imos[i] == 1);
        dissaborable[i] += dissaborable[i-1];
    }
    rep(m){
        if(p[i].first){
            if(dissaborable[p[i].second-1] - dissaborable[p[i].first-1] == 0){
                ans.push_back(i+1);
            }
        }else{
            if(dissaborable[p[i].second-1] == 0){
                ans.push_back(i+1);
            }
        }
    }
    cout << (int)ans.size() << endl;
    for(int x: ans) cout << x << endl;
}
