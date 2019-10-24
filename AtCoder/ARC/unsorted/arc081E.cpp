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
#define MAX 200005
#define INF 1410065408
#define EPS 1e-9
#define DEBUG
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int n, tmpi;
char tmpc;
string s;

int calc(int i, vector<int> dp, vector<int> dpi, vector<char> dpc, map<char,int> mp[]){
    int tmp = INF;
    tmpi = -1;
    for(char c='a'; c<='z'; c++){
        if(mp[i].count(c) == 0){
            tmpc = c;
            tmpi = n;
            tmp = 1;
            break;
        }else if(s[i] != c && dp[mp[i][c]] + 1 < tmp){
            tmpc = c;
            tmpi = mp[i][c];
            tmp = dp[mp[i][c]] + 1;
        }
    }
    return tmp;
}

signed main(){
    cin >> s;
    n = (int)s.length();
    vector<int> dp(n+1, 0), dpi(n+1);
    vector<char> dpc(n+1);
    map<char, int> mp[n+1];

    for(int i=n-1;i>=0;i--){
        for(auto itr=mp[i+1].begin();itr!=mp[i+1].end();itr++){
            mp[i][itr->first] = itr->second;
        }
        mp[i][s[i]] = i;
    }

    dp[n-1] = 1;
    dpi[n-1] = n;
    dpc[n-1] = s[n-1] == 'a' ? 'b' : 'a';
    for(int i=n-2;i>=0;i--){
        dp[i] = calc(i, dp, dpi, dpc, mp);
        dpi[i] = tmpi;
        dpc[i] = tmpc;
    }

    #ifdef DEBUG
        rep(n){
            printf("s[%2d]=%2c %2d %2d %2c\n", i, s[i], dp[i], dpi[i], dpc[i]);
        }
    #endif

    string ans = "";
    int next = 0;
    rep(dp[0]){
        ans += dpc[next];
        next = dpi[next];
    }
    printf("%s\n", ans.c_str());
}
