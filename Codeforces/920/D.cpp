#include <bits/stdc++.h>

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

int dp[5002][5001], used[5002][5001];

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);

    int n,k,v;
    scanf("%d %d %d", &n, &k, &v);
    vector<int> a(n);
    rep(n){
        scanf("%d", &a[i]);
        if(a[i] == v){
            printf("YES\n");
            return 0;
        }
    }
    
    int total = accumulate(all(a), 0);
    if(total < v){
        printf("NO\n");
        return 0;
    }

    
    dp[0][0] = 1;
    repp(i, n){
        repp(j, k){
            if(!dp[i][j]) continue;
            dp[i+1][j] = 1;
            dp[i+1][(j+a[i])%k] = 1;
            used[i][j] = 0;
            used[i][(j+a[i])%k] = 1;
        }
    }

    if(v%k == 0){
        printf("YES\n");
        reppp(i, 1, n){
            printf("%d %d 1\n", (a[i]+k-1)/k, i+1);
            a[0] += a[i];
            a[i] = 0;
        }
        if(v) printf("%d 1 2\n", v/k);
        return 0;
    }

    if(!dp[n][v%k]){
        printf("NO");
        return 0;
    }
    set<int> b;
    int j = v%k;
    for(int i=n-1;i>=0;i--){
        if(used[i][j]){
            b.insert(i);
            j = (j-(a[i]%k)+k)%k;
            cerr << i << " " << j << endl;
        }
    }

    int xrep = 0, yrep = -1;
    int nb = (int)b.size();
    if(nb){
        xrep = *b.begin();
        rep(n){
            if(b.find(i) == b.end()){
                yrep = i;
            }
        }
    }else{
        xrep = -1;
        yrep = 0;
    }

    vector< pair<int, Pii> > ans;

    if(xrep != -1){
        rep(n){
            if(i == xrep || b.find(i) == b.end()) continue;
            if(a[i]+k-1 <= 0) continue;
            ans.emplace_back((a[i]+k-1)/k, Pii(i+1, xrep+1));
            a[xrep] += a[i];
            a[i] = 0;
        }
    }
    if(yrep != -1){
        rep(n){
            if(i == yrep || b.find(i) != b.end()) continue;
            if(a[i]+k-1 <= 0) continue;
            ans.emplace_back((a[i]+k-1)/k, Pii(i+1, yrep+1));
            a[yrep] += a[i];
            a[i] = 0;
        }
    }
    rep(n){
        cerr << a[i] << " " ;
    }
    cerr << endl;

    int tmp = 0;
    if(xrep != -1) tmp += a[xrep];
    if(yrep != -1) tmp += a[yrep]/k*k;
    if(tmp < v){
        printf("NO\n");
        return 0;
    }else{
        printf("YES\n");
    }

    if(yrep != -1 && a[xrep]!= v && v-a[xrep]+k-1 > 0){
        ans.emplace_back((v-a[xrep]+k-1)/k, Pii(yrep+1, xrep+1));
        int diff = min(a[yrep], (v-a[xrep]+k-1)/k*k);
        a[xrep] += diff;
        a[yrep] -= diff;
    }
    if(a[xrep] != v && a[xrep]-v+k-1 > 0){
        ans.emplace_back((a[xrep]-v+k-1)/k, Pii(xrep+1, (xrep+1)%n+1));
        int diff = min(a[xrep], (a[xrep]-v+k-1)/k*k);
        a[xrep] -= diff;
        a[(xrep+1)%n+1] += diff;
    }

    rep(n){
        cerr << a[i] << " " ;
    }
    cerr << endl;

    rep((int)ans.size()){
        if(ans[i].first) printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
    }

    return 0;
}
