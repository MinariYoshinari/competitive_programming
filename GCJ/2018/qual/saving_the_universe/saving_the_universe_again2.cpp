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
    int t;
    cin >> t;
    ll d;
    string s;
    reppp(tt, 1, t+1){
        cin >> d >> s;
        cout << "Case #" << tt << ": ";

        int n = (int)s.length();

        vector<int> c_idx;
        c_idx.push_back(0);
        ll shoot_damage = 1, total_damage = 0;
        int count_s = 0;
        rep(n){
            if(s[i] == 'S'){
                total_damage += shoot_damage;
                count_s++;
            }else{
                shoot_damage *= 2;
                c_idx.push_back(i);
            }
        }

        if(count_s > d){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        int ans = 0;
        while(total_damage > d){
            int idx = n, damage = 0, swap_c = n;
            reppp(i, 1, (int)c_idx.size()){
                if(s[c_idx[i]+1] == 'S'){
                    idx = c_idx[i];
                    swap_c = i;
                    damage = pow(2, i);
                }
            }
            if(idx == n) break;

            swap(s[idx], s[idx+1]);
            ans++;
            c_idx[swap_c]++;
            total_damage = total_damage - damage + (damage >> 1);
        }

        if(total_damage > d){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << ans << endl;
        }
    }
}
