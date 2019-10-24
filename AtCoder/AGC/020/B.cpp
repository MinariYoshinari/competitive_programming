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
    int k;
    ll max_ = 2, min_ = 2;
    cin >> k;
    vector<ll> a(k);
    rep(k){
        cin >> a[i];
    }
    a.push_back((ll)(INT_MAX/2-1));

    for(int i=k-1;i>=0;i--){
        min_ = (min_ + a[i] - 1LL) / a[i] * a[i];
    }

    ll tmp = min_;
    rep(k){
        tmp = tmp / a[i] * a[i];
    }
    if(tmp != 2){
        cout << -1 << endl;
        return 0;
    }

    for(int i=k-1;i>=0;i--){
        max_ = (max_ + a[i] - 1LL) / a[i] * a[i] + a[i] - 1;
        if(i == 0) break;
        max_ = max_ / a[i-1] * a[i-1];
    }

    tmp = max_;
    rep(k){
        tmp = tmp / a[i] * a[i];
    }
    if(tmp != 2){
        cout << -1 << endl;
        return 0;
    }

    cout << min_ << " " << max_ << endl;
    return 0;
}
