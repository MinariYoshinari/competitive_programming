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
#include<numeric>

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
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

int h,w;
ll ha,wb, ans1  = 0, ans2 = 0;

int search_hv(vector< vector<int> > hv){
    rep(h/2){
        repp(j, w){
            if(hv[i][j] % 2 == 1) return 0;
        }
    }
    return 1;
}

int search_wv(vector< vector<int> > wv){
    rep(h){
        repp(j, w/2){
            if(wv[i][j] % 2 == 1) return 0;
        }
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> h >> w >> ha >> wb;

    vector< vector<int> > hv(h/2, vector<int>(w, 0)), wv(h, vector<int>(w/2, 0));
    vector<string> mp(h);
    rep(h){
        cin >> mp[i];
        repp(j, w){
            if(mp[i][j] == 'S'){
                hv[min(i, h-1-i)][j]++;
                wv[i][min(j, w-1-j)]++;
            }
        }
    }

    vector< vector<int> > hv2(hv), wv2(wv);
    vector<string> mp2(mp);

    rep(h/2){
        repp(j, w){
            if(hv[i][j] == 0) continue;
            
            else if(hv[i][j] == 1){
                hv[i][j] = 0;
                int jj = min(j, w-1-j);
                if(mp[i][j] == 'S'){
                    mp[i][j] = '.';
                    wv[i][jj]--;
                }else{
                    mp[h-1-i][j] = '.';
                    wv[h-1-i][jj]--;
                }
                if(search_hv(hv)) ans1 += ha;
                if(search_wv(wv)) ans1 += wb;

            }else{
                hv[i][j] = 1;
                ll tmp1 = 0, tmp2 = 0;
                int jj = min(j, w-1-j);
                wv[i][jj]--;
                if(search_hv(hv)) tmp1 += ha;
                if(search_wv(wv)) tmp1 += wb;
                wv[i][jj]++;
                wv[h-1-i][jj]--;
                if(search_hv(hv)) tmp2 += ha;
                if(search_wv(wv)) tmp2 += wb;
                wv[h-1-i][jj]++;
                ans1 += max(tmp1, tmp2);
                mp[i][j] = '.';
                mp[h-1-i][j] = '.';
                hv[i][j] = 0;
                wv[i][jj]--;
                wv[h-1-i][jj]--;
                if(search_hv(hv)) ans1 += ha;
                if(search_wv(wv)) ans1 += wb;
            }
        }
    }

    rep(h){
        repp(j, w/2){
            if(wv2[i][j] == 0) continue;
            
            else if(wv2[i][j] == 1){
                wv2[i][j] = 0;
                int ii = min(i, h-1-i);
                if(mp2[i][j] == 'S'){
                    mp2[i][j] = '.';
                    hv2[ii][j]--;
                }else{
                    mp2[i][w-1-j] = '.';
                    hv2[ii][w-1-j]--;
                }
                if(search_hv(hv2)) ans2 += ha;
                if(search_wv(wv2)) ans2 += wb;

            }else{
                wv2[i][j] = 1;
                ll tmp1 = 0, tmp2 = 0;
                int ii = min(i, h-1-i);
                hv2[ii][j]--;
                if(search_hv(hv2)) tmp1 += ha;
                if(search_wv(wv2)) tmp1 += wb;
                hv2[ii][j]++;
                hv2[ii][w-1-j]--;
                if(search_hv(hv2)) tmp2 += ha;
                if(search_wv(wv2)) tmp2 += wb;
                hv2[ii][w-1-j]++;
                ans2 += max(tmp1, tmp2);
                mp2[i][j] = '.';
                mp2[i][w-1-j] = '.';
                wv2[i][j] = 0;
                hv2[ii][j]--;
                hv2[ii][w-1-j]--;
                if(search_hv(hv2)) ans2 += ha;
                if(search_wv(wv2)) ans2 += wb;
            }
        }
    }
    cout << ans1 << endl << ans2 << endl;
}
