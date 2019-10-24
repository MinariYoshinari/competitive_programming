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

int n;
vector<int> d;

int calc_diff(){
    int ret = INF;
    rep(n){
        reppp(j, i+1, n){
            int diff = abs(d[i]-d[j]);
            diff = min(diff, 24-diff);
            ret = min(ret, diff);
        }
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    if(n==1){
        int d;
        cin >> d;
        cout << d << endl;
        return 0;
    }

    d.push_back(0);
    rep(n){
        int tmp;
        cin >> tmp;
        d.push_back(tmp);
    }
    sort(all(d));

    for(int i=1;i<=n;i+=2){
        d[i] = 24 - d[i];
    }
    int ans1 = calc_diff();

    rep(n){
        d[i] = 24 - d[i];
    }
    int ans2 = calc_diff();

    cout << max(ans1, ans2) << endl;
    return 0;
}
