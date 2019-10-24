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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};


struct status{
    int index, last_mod, count_mod, count_lr;
};

map<int, map<int, map<int, map<int, int> > > > used;

status make_status(int a, int b, int c, int d){
    status ret;
    ret.index = a;
    ret.last_mod = b;
    ret.count_mod = c;
    ret.count_lr = d;
    return ret;
}

signed main(){
    string ss;
    cin >> ss;
    vector<int> ans;
    int n = (int)ss.length();
    
    queue<status> q;
    if(ss[0] == '('){
        q.push(make_status(0, 101, 0, 1));
    }else{
        q.push(make_status(0, 0, 1, 1));
    }

    while(!q.empty()){
        status s = q.front(); q.pop();

        //printf("status(%d, %d, %d, %d)\n", s.index, s.last_mod, s.count_mod, s.count_lr);
        
        if(s.index == n-1){
            if(s.count_lr == 0){
                //printf("%d %d %d\n", s.last_mod, s.count_mod, s.count_lr);
                if(s.last_mod == 101){
                    ans.pb(s.count_mod);
                }else{
                    ans.pb(s.last_mod + s.count_mod);
                }
            }
            continue;
        }

        if(ss[s.index+1] == '('){
            if(!used[s.index+1][s.last_mod][s.count_mod][s.count_lr+1]){
                used[s.index+1][s.last_mod][s.count_mod][s.count_lr+1] = 1;
                q.push(make_status(s.index+1, s.last_mod, s.count_mod, s.count_lr+1));
            }
            if(s.count_lr - 1 >= 0){
                if(!used[s.index+1][s.index+1][s.count_mod+1][s.count_lr-1]){
                    used[s.index+1][s.index+1][s.count_mod+1][s.count_lr-1] = 1;
                    q.push(make_status(s.index+1, s.index+1, s.count_mod+1, s.count_lr-1));
                }
            }
        }else{
            if(!used[s.index+1][s.last_mod][s.count_mod][s.count_lr-1]){
                if(s.count_lr - 1 >= 0){
                    used[s.index+1][s.last_mod][s.count_mod][s.count_lr-1] = 1;
                    q.push(make_status(s.index+1, s.last_mod, s.count_mod, s.count_lr-1));
                }
            }
            if(!used[s.index+1][s.index+1][s.count_mod+1][s.count_lr+1]){
                used[s.index+1][s.index+1][s.count_mod+1][s.count_lr+1] = 1;
                q.push(make_status(s.index+1, s.index+1, s.count_mod+1, s.count_lr+1));
            }
        }

    }

    cout << *min_element(all(ans)) << endl;
}
