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
#define MAX 1001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    int n, m, tmp, ans = 0;
    cin >> n >> m;
    vector< map<int, int> > a(m);
    vector<int> count(m, 0);
    rep(n){
        cin >> tmp;
        a[tmp%m][tmp]++;
        count[tmp%m]++;
    }

    reppp(i, 1, (m-1)/2){
        int n_i = count[i], n_j = count[m-i];
        if(n_i > n_j){
            swap(a[i], a[m-i]);
            swap(n_i, n_j);
        }

        // 同じ数字のペア
        if(n_j - n_i >= 2)
            for(auto itr = a[m-i].begin(); itr != a[m-i].end(); ++itr){
                int dec_count = min(itr->second, n_j-n_i);
                if(dec_count % 2 == 1) dec_count--;
                if(dec_count > 0){
                    n_j -= dec_count;
                    ans += dec_count/2;
                }
            }
            //cout << ans << " ";
        
        // 合わせてmの倍数
        ans += min(n_i, n_j);
        //cout << ans << endl;
    }

    ans += count[0]/2;
    if(m % 2 == 0) ans += count[m/2]/2;
    
    cout << ans << endl;
}