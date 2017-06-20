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

signed main(){
    vector<int> rate(9, 0);
    int N, a, r, ansmin = 0, ansmax;
    cin >> N;
    rep(N){
        cin >> a;
        r = min(8, a / 400);
        if(rate[r] == 0 && r < 8){
            ansmin++;
        }
        rate[r]++;
    }
    if(ansmin == 0){
        ansmin = 1;
        rate[8]--;
    }

    if(rate[8] > 0){
        ansmax = ansmin+rate[8];
    }else{
        ansmax = ansmin;
    }
    cout << ansmin << " " << ansmax;
}
