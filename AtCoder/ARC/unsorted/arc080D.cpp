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
    int h,w,n;
    cin >> h >> w >> n;
    map<int, int> cnt;

    rep(n){
        cin >> cnt[i+1];
    }

    auto iter = cnt.begin();
    rep(h){
        if(i % 2 == 0){
            repp(j, w){
                cout << iter->first << " ";
                (iter->second)--;
                if(iter->second == 0) iter++;
            }
        }else{
            vector<int> v(w);
            for(int j=w-1;j>=0;j--){
                v[j] = iter->first;
                (iter->second)--;
                if(iter->second == 0) iter++;
            }
            repp(j, w){
                cout << v[j] << " ";
            }
        }
        cout << endl;
    }
}