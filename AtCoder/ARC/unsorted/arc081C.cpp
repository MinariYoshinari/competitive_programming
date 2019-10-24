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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, tmp;
    cin >> n;
    map<ll, ll> mp;
    rep(n){
        cin >> tmp;
        mp[tmp]++;
    }

    vector<ll> rec;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++){
        if(itr->second >= 2){
            rec.pb(itr->first);
        }
    }

    
    if((int)rec.size()== 0){
        printf("0");
    }else{
        sort(rall(rec));
        if((int)rec.size() == 1){
            if(mp[rec[0]] >= 4){
                printf("%lld", rec[0]*rec[0]);
            }else{
                printf("0");
            }
        }else{
            if(mp[rec[0]] >= 4){
                printf("%lld", rec[0]*rec[0]);
            }else{
                printf("%lld", rec[0]*rec[1]);
            }
        }
    }
  
}
