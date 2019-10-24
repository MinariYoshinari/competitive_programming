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
#include<numeric>
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
    int N;
    cin >> N;
    vector<ll> a(N+1);
    vector<Pll> p(N+1, Pll(0, 0));
    reppp(i, 1, N){
        cin >> a[i];
        reppp(j, 1, i){
            if(i % j == 0) p[j].first += a[i];
        }
    }
    reppp(i, 1, N) p[i].second = i;
    sort(all(p));

    while(p[0].first < 0){
        // cout << p[0].second << endl;
        reppp(j, 0, N) p[j].first = 0;
        reppp(i, 1, N){
            if(i % p[0].second == 0) a[i] = 0;
            reppp(j, 1, i){
                if(i % j == 0) p[j].first += a[i];
            }
        }
        reppp(j, 1, N) p[j].second = j;
        sort(all(p));
        // reppp(i, 1, N) cout << a[i] << " ";
        // cout << endl;
        // rep(N+1) cout << p[i].first << " " << p[i].second << endl;
    }

    cout << accumulate(all(a), 0) << endl;

}