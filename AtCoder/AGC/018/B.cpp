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
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

int eliminate(vector< vector<int> > a, int n, int m){
    vector<int> sports(m, 0);
    int ret = 300;
    repp(k, m){
        rep(n){
            int j = 0;
            while(sports[a[i][j]] == -1) j++;
            sports[a[i][j]]++;
        }
        int max_sport = max_element(all(sports)) - sports.begin();
        ret = min(ret, sports[max_sport]);
        rep(m){
            if(sports[i] == -1 || i == max_sport) sports[i] = -1;
            else sports[i] = 0;
        }
    }
    return ret;
}

signed main(){
    int n,m;
    cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(m));
    rep(n){
        repp(j, m){
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    cout << eliminate(a, n, m);
}
