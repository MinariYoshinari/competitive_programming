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

const ll MOD = 1000000007;
const double EPS = 1e-9;

int search(vector<int> v, int target){
    if(v[0] > target) return -1;
    int ok = 0, ng = (int)v.size();
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        if(v[mid] > target){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return v[ok];
}

int main(){
    int t;
    cin >> t;
    ll d;
    string s;
    reppp(tt, 1, t+1){
        cin >> d >> s;
        cout << "Case #" << tt << ": ";
        
        vector<int> c_idx;
        map<ll, set<int> > damage_idx;
        ll shoot_damage = 1, total_damage = 0, count_s = 0;
        rep((int)s.length()){
            if(s[i] == 'S'){
                count_s++;
                damage_idx[shoot_damage].insert(i);
                total_damage += shoot_damage;
            }else{
                c_idx.push_back(i);
                shoot_damage *= 2;
            }
        }

        if(count_s > d){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        int ans = 0;
        while(total_damage > d){
            ll max_shoot_damage = 1LL << (int)c_idx.size();
            while(damage_idx[max_shoot_damage].empty()) max_shoot_damage >>= 1;
            debug(max_shoot_damage);

            total_damage = total_damage - max_shoot_damage + (max_shoot_damage >> 1);
            debug(total_damage);

            int swap_s = *damage_idx[max_shoot_damage].begin();
            debug(swap_s);
            int swap_c = search(c_idx, swap_s);
            debug(swap_c);
            ans += swap_s - swap_c;
            damage_idx[max_shoot_damage].erase(swap_s);
            damage_idx[max_shoot_damage >> 1].insert(swap_s);
            *lower_bound(all(c_idx), swap_s-1) = swap_s;
        }

        cout << ans << endl;
    }
}