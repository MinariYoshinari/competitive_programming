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

int waffle[101][101];

int calc_total(int si, int sj, int gi, int gj){
    int ret = waffle[gi][gj];
    if(si) ret -= waffle[si-1][gj];
    if(sj) ret -= waffle[gi][sj-1];
    if(si != 0 && sj != 0) ret += waffle[si-1][sj-1];
    return ret;
}

int main(){
    int t;
    scanf("%d", &t);

    repp(tt, t){
        int r, c, h, v, flag = 1;
        scanf("%d %d %d %d", &r, &c, &h, &v);
        rep(r){
            char s[c];
            scanf("%s", s);
            repp(j, c){
                if(s[j] == '@') waffle[i][j] = 1;
                else waffle[i][j] = 0;
                if(i) waffle[i][j] += waffle[i-1][j];
                if(j) waffle[i][j] += waffle[i][j-1];
                if(i != 0 && j != 0) waffle[i][j] -= waffle[i-1][j-1];
            }
        }
        int chips = waffle[r-1][c-1];

        if(chips % ((h+1)*(v+1)) != 0){
            flag = 0;
        }else if(chips == 0){
            flag = 1;
        }else{
            int nxt = chips/(h+1), cnt = 0;
            flag = 1;
            vector<int> vh, vv;
            vh.push_back(0);
            rep(r-1){
                if(waffle[i][c-1] == nxt){
                    nxt += chips/(h+1);
                    cnt++;
                    vh.push_back(i);
                }else if(waffle[i][c-1] > nxt){
                    flag = 0;
                    break;
                }
            }
            if(cnt != h) flag = 0;

            nxt = chips/(v+1);
            cnt = 0;
            vv.push_back(0);
            if(flag) repp(j, c-1){
                if(waffle[r-1][j] == nxt){
                    nxt +=  chips/(v+1);
                    cnt++;
                    vv.push_back(j);
                }else if(waffle[r-1][j] > nxt){
                    flag = 0;
                    break;
                }
            }
            if(cnt != v) flag = 0;

            int part = chips/((h+1)*(v+1));
            reppp(hi, 1, (int)vh.size()){
                reppp(vi, 1, (int)vv.size()){
                    if(calc_total(vh[hi-1]+1, vv[vi-1]+1, vh[hi], vv[vi]) != part){
                        flag = 0;
                        break;
                    }
                }
                if(!flag) break;
            }
        }
        printf("Case #%d: %s\n", tt+1, (flag?"POSSIBLE":"IMPOSSIBLE"));
    }
}
