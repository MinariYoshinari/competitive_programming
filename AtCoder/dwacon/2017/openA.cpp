#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cassert>
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
    ll h,m,s,c[2];
    cin >> h >> m >> s;
    h %= 12;
    cin >> c[0] >> c[1];
    if(c[0] < c[1]){
        cout << -1 << endl;
        return 0;
    }

    ll clk[3] = {0, 0, 0};
    ll n[2] = {0, 0};
    vector< pair<ll, ll> > check;
    ll hh = 0, mm = 0, ss = 0; 
    ll tt = 0;
    check.emplace_back(0, 1);
    n[1]++;
    while(hh < 12){
        check.emplace_back(tt, 0);
        n[0]++;
        while(mm < 60){
            while(ss < 60){
                if((clk[1]-clk[2])*(clk[1]+12-clk[2]-720) <= 0){
                    if(tt % 7200 != 0 && (tt % 7200 != 7198)){
                        check.emplace_back(tt+1, 0);
                        n[0]++;
                    }
                }
                if((clk[0]-clk[1])*(clk[0]+1-clk[1]-12) <= 0){
                    if((ll)tt != 0 && (ll)tt != 86398){
                        check.emplace_back(tt+1, 1);
                        n[1]++;
                    }
                }
                ss++;
                tt += 2;
                clk[0] += 1; //0.1/12;
                clk[1] += 12; //0.1;
                clk[2] += 720; //6;
                rep(3) if(clk[i] >= 43200) clk[i] -= 43200;
            }
            ss = 0;
            mm++;
        }
        mm = 0;
        hh++;
    }

    ll ans[2] = {-1, -1};
    tt = 2*(3600*h + 60*m + s);
    int ii = 0;
    int nn = (int)check.size();
    while(ii < nn && check[ii].first <= tt) ii++;
    reppp(i, ii, nn){
        c[check[i].second]--;
        if(c[0] == 0 && c[1] == 0 && ans[0] == -1){
            ans[0] = check[i].first + 1 - tt;
        }else if(ans[0] != -1 && ans[1] == -1){
            ans[1] = check[i].first - 1 - tt;
            break;
        }
    }

    tt = 86400 - tt;
    ll d = min(c[0]/n[0], c[1]/n[1]);
    c[0] -= d*n[0];
    c[1] -= d*n[1];
    tt += d*86400;
    if(c[0] == 0 && c[1] == 0 && ans[0] == -1){
        ans[0] = tt;
    }

    if(c[0] >= 0 || c[1] >= 0) repp(i, nn){
        c[check[i].second]--;
        if(c[0] == 0 && c[1] == 0 && ans[0] == -1){
            ans[0] = check[i].first + 1 + tt;
        }else if(ans[0] != -1 && ans[1] == -1){
            ans[1] = check[i].first - 1 + tt;
            break;
        }
    }

    tt = 2*(3600*h + 60*m + s);
    if(ans[0] != -1 && ans[1] != -1){
        if((tt+ans[0])/2 % 43200 == 0) ans[0] += 2;
        if((tt+ans[1])/2 % 43200 == 0) ans[1] += 2;
        ans[0] /= 2;
        ans[1] /= 2;
        cout << ans[0] <<  " " << ans[1] << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
