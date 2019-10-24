#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
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

signed main(){
    int n,c, max_t = 0;
    cin >> n >> c;
    vector<Pii> programs[c];

    rep(n){
        int s,t,cc;
        cin >> s >> t >> cc;
        programs[cc-1].emplace_back(s*2-1, t*2);
        max_t = max(max_t, max(s*2-1, t*2));
    }

    vector<int> ss, tt;
    rep(c){
        if(programs[i].empty()) continue;
        sort(all(programs[i]));
        int np = (int)programs[i].size();
        if(np == 1){
            ss.push_back(programs[i][0].first);
            tt.push_back(programs[i][0].second);
        }else{
            int  j = 0;
            while(j < np){
                if(j < np-1 && programs[i][j+1].first <= programs[i][j].second + 1){
                    int jj = j+1;
                    while(jj < np && programs[i][jj].first <= programs[i][jj-1].second + 1) jj++;
                    jj--;
                    ss.push_back(programs[i][j].first);
                    tt.push_back(programs[i][jj].second);
                    j = jj+1;
                }else{
                    ss.push_back(programs[i][j].first);
                    tt.push_back(programs[i][j].second);
                    j++;
                }
            }
        }

    }
    sort(all(ss));
    sort(all(tt));

    vector<int> times(200003);
    times[0] = 0;
    int si = 0, ti = 0;
    int sn = (int)ss.size();
    int tn = sn;
    
    reppp(t, 1, max_t){
        times[t] = times[t-1];
        while(ti < tn && tt[ti] == t){
            times[t]--;
            ti++;
        }
        while(si < sn && ss[si] == t){
            times[t]++;
            si++;
        }
    }
    cout << *max_element(all(times)) << endl;
}
