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

signed main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N, 0), mp(N+1, 0);
    rep(N){
        cin >> a[i];
        mp[a[i]]++;
    }
    
    vector<int> mpb;
    int idx, after, ans;
    rep(M){
        ans = 0;
        cin >> idx >> after;
        mp[a[idx-1]]--; mp[after]++;
        a[idx-1] = after;
        mpb = mp;
        int pre = -1;
        for(int i=N;i>=1;i--){
            if(mpb[i] > 0){
                mpb[i]--;
                pre = i;
            }else if(mpb[i] == 0){
                if(pre != -1 && mpb[pre] > 0){
                    mpb[pre]--;
                }else{
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
