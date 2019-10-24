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
// #define INF 1410065408
#define INF 6000
#define EPS 1e-9
    
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};
    

int max_[52][52][52];
int min_[52][52][52];
string s;

void solve(int l, int r, int k){
    // すでに何者かによって計算されていた……
    if(max_[l][r][k] != 0 && min_[l][r][k] != 0) return;

    // 区間の長さが1のとき
    if(r - l == 1){
        if(k == 0){
            if(s[l] != '+' && s[l] != '-'){
                max_[l][r][0] = s[l];
                min_[l][r][0] = s[l];
            }else{
                max_[l][r][0] = -INF;
                min_[l][r][0] = -INF;
            }
        }else{
            max_[l][r][k] = 9;
            min_[l][r][k] = 0;
        }
        return;
    }

    // 今から再帰で計算する
    for(int m=1;m<r-l;m+=2){
        if(s[r-1] == '+' || s[r-1] == '-'){
            for(int kk=0;kk<=k;kk++){
                solve(l, m, kk);
                solve(m, r-1, k-kk);
            }
        }else{
            for(int kk=0;kk<=k-1;kk++){
                solve(l, m, kk);
                solve(m, r-1, k-1-kk);
            }
        }
    }


}

signed main(){
    int k;
    cin >> k >> s;
    int n = (int)s.length();

    if(n % 2 == 0){
        cout << "NG";
        return 0;
    }

    solve(0, n, k);

    int ans = -INF;
    rep(k+1) ans = max(ans, max_[0][n][i]);

    if(ans != -INF){
        cout << "OK" << endl;
        cout << ans << endl;
    }else{
        cout << "NG" << endl;
    }
    return 0;
}