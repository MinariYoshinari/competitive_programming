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
    string un = "UNRESTORABLE", s, t;
    cin >> s >> t;
    int tn = (int)t.length(), start = -1;
    rep((int)s.length()){
        int flag = 1;
        repp(j, tn){
            if(s[i+j] != '?' && s[i+j] != t[j]){
                flag = 0;
            }
        }
        if(flag) start = i;
        
    }
    if(start == -1){
        cout << un;
        return 0;
    }
    reppp(i, start, start+tn-1) s[i] = t[i-start];
    rep((int)s.length()){
        if(s[i] == '?') cout << 'a';
        else cout << s[i];
    }
    return 0;
}