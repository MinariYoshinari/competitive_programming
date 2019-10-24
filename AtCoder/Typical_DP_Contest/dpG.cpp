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
#define MOD 1000000007LL
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
    string s; ll k;
    cin >> s >> k;
    int n = (int)s.length();

    ll dp[n][26];
    fill(dp[0], dp[n], 0);

    dp[n-1][s[n-1]-'a'] = 1;
    for(int i=n-2; i>=0; i--){
        repp(j, 26){
            if(j == (int)(s[i] - 'a')){
                dp[i][j] = 1LL;
                repp(jj, 26){
                    dp[i][j] += dp[i+1][jj];
                    if(dp[i][j] > k) break;
                }
            }else{
                dp[i][j] = dp[i+1][j];
            }
            //printf("%c%5lld ", j+'a', dp[i][j]);
        }
        //printf("\n");
    }
    
    int i = 0;
    do{
        int j  = 0;
        while(k > dp[i][j] && j < 26){
            k -= dp[i][j];
            j++;
        }
        if(j >= 26){
            if(i == 0) cout << "Eel";
            break;
        }
        cout << (char)('a'+j);
        while(i < n && (int)('a'+j) != s[i]) i++;
        k--;
        i++;
    }while(k > 0LL);
    cout << endl;
    return 0;
}