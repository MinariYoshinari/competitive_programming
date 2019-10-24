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
typedef pair<ll, Pii> Plii;
struct edge{int from, to; ll cost;};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    pair<ll, char> cities[n+1];
    vector<int> p;
    int flag_r = 0, flag_b = 0, last_r = -1, last_b = -1;
    ll start, ans = 0LL;
    rep(n){
        cin >> cities[i].first >> cities[i].second;
        if(i == 0) start = cities[0].first;
        cities[i].first -= start;
        if(cities[i].second == 'P') p.push_back(i);
    }
    int np = (int)p.size();

    if(np == 0){
        int first_r = -1, first_b = -1;
        rep(n){
            if(cities[i].second == 'R'){
                if(first_r == -1) first_r = i;
                else last_r = i;
            }else if(cities[i].second == 'B'){
                if(first_b == -1) first_b = i;
                else last_b = i;
            }
        }
        if(first_r != -1 && last_r != -1){
            ans += cities[last_r].first - cities[first_r].first;
        }
        if(first_b != -1 && last_b != -1){
            ans += cities[last_b].first - cities[first_b].first;
        }

        cout << ans << endl;
        return 0;
    }

    repp(j, p[0]){
        if(cities[j].second == 'R'){
            flag_r = 1;
            last_r = j;
        }else if(cities[j].second == 'B'){
            flag_b = 1;
            last_b = j;
        }
    }
    if(flag_r){
        ans += cities[p[0]].first - cities[last_r].first;
    }
    if(flag_b){
        ans += cities[p[0]].first - cities[last_b].first;
    }
    debug(ans);

    flag_r = 0; flag_b = 0;
    reppp(j, p[np-1], n){
        if(cities[j].second == 'R'){
            flag_r = 1;
            last_r = j;
        }else if(cities[j].second == 'B'){
            flag_b = 1;
            last_b = j;
        }
    }
    if(flag_r){
        ans += cities[last_r].first - cities[p[np-1]].first;
    }
    if(flag_b){
        ans += cities[last_b].first - cities[p[np-1]].first;
    }
    debug(ans);

    reppp(i, 1, np){
        flag_r = 0; flag_b = 0;
        reppp(j, p[i-1], p[i]){
            if(cities[j].second == 'R') flag_r = 1;
            else if(cities[j].second == 'B') flag_b = 1;
        }
        ans += (cities[p[i]].first - cities[p[i-1]].first)  * (!flag_r&!flag_b?1:2);
    }

    cout << ans <<endl;
    return 0;
}
