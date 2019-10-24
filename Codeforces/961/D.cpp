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

int pairs[4][3] = {{0, 1, 2}, {0, 2, 1}, {1, 2, 0}, {0, 1, 3}};

bool on_the_line(ll dx, ll dy, Pll u, Pll v){
    return dx * (u.second - v.second) == dy * (u.first - v.first);
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(5);
    vector<Pll> ps(n);
    rep(5) v[i] = i;
    rep(n) cin >> ps[i].first >> ps[i].second;

    if(n <= 4){
        cout << "YES" << endl;
        return 0;
    }

    do{
        ll adx = ps[v[1]].first - ps[v[0]].first;
        ll ady = ps[v[1]].second - ps[v[0]].second;
        ll bdx = ps[v[3]].first - ps[v[2]].first;
        ll bdy = ps[v[3]].second - ps[v[2]].second;
        
        if(!on_the_line(adx, ady, ps[v[4]], ps[v[0]]) && !on_the_line(bdx, bdy, ps[v[4]], ps[v[3]])) continue;
        int succeed = 1;
        int b_idx[2] = {-1, -1};
        rep(n){
            if(i == v[0] || i == v[1]) continue;
            if(on_the_line(adx, ady, ps[i], ps[v[0]])) continue;
            if(b_idx[0] == -1){
                b_idx[0] = i;
            }else if(b_idx[1] == -1){
                b_idx[1] = i;
                bdx = ps[i].first - ps[b_idx[0]].first;
                bdy = ps[i].second - ps[b_idx[0]].second;
            }else{
                if(!on_the_line(bdx, bdy, ps[i], ps[b_idx[0]])){
                    succeed = 0;
                    break;
                }
            }
        }
        if(!succeed) continue;

        cout << "YES" << endl;
        return 0;
    }while(next_permutation(all(v)));

    cout << "NO" << endl;
    return 0;
    
}
