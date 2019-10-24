#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<bitset>

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

int main(){
    string s;
    cin >> s;
    int n = (int)s.length();
    int cnt = 0, m = -2526;
    rep(n){
        if(s[i] == '2') cnt++;
        else cnt--;
        if(cnt < 0){
            cout << -1 << endl;
            return 0;
        }
        m = max(cnt, m);
    }
    if(cnt == 0) cout << m << endl;
    else cout << -1 << endl;
    return 0;
}  
