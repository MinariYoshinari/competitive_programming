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
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<int, int> cards[m];
    vector<int> counts(m, 0);
    rep(n){
        int tmp;
        cin >> tmp;
        cards[tmp%m][tmp]++;
        counts[tmp%m]++;
    }

    int ans = counts[0] / 2;
    reppp(i, 1, (m-1)/2){
        if(counts[i] < counts[m-i]){
            swap(counts[i], counts[m-i]);
            swap(cards[i], cards[m-i]);
        }
        int diff = counts[i] - counts[m-i];
        if(diff >= 2){
            for(auto itr=cards[i].begin(); itr!=cards[i].end(); ++itr){
                if(itr->second >= 2){
                    int tmp = min(diff, itr->second)/2;
                    ans += tmp;
                    counts[i] -= tmp*2;
                    diff = counts[i] - counts[m-i];
                    if(diff == 0) break;
                }
            }
        }
        ans += min(counts[i], counts[m-i]);
        //cout << i << " " << ans << endl;

    }
    if(m % 2 == 0){
        ans += counts[m/2]/2;
    }
    cout << ans;
}
