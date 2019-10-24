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
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int N; ll A, B;
    cin >> N >> A >> B;
    vector<ll> hs;
    rep(N){
        ll h;
        cin >> h;
        hs.push_back(h);
    }

    ll max_h = *max_element(all(hs));
    //ll min_ans = (max_h+A-1) / A, max_ans = (max_h+B-1) / B;
    ll min_ans = 1, max_ans = (max_h+B-1) / B;
    ll ans;
    while(min_ans < max_ans){
        ans = (max_ans + min_ans) / 2;
        ll check = 0;
        rep(N){
            if(hs[i] <= B*ans) continue;
            ll diff = A - B;
            check += (hs[i] - B*ans + diff - 1) / diff;
        }
        if(check <= ans){
            max_ans = ans;
        }else{
            min_ans = ans + 1;
        }
    }
    cout << min_ans;
}