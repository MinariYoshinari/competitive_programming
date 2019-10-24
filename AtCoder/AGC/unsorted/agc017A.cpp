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
struct edge{int from, to; ll cost;};

map<Pll, ll> memo;

ll comb(ll n, ll r){
    if(n == r || r == 0){
        return 1;
    }else if(r == 1){
        return n;
    }else if(memo[Pll(n, r)] != 0){
        return memo[Pll(n, r)];
    }else{
        ll tmp = comb(n-1, r-1) + comb(n-1, r);
        memo[Pll(n, r)] = tmp;
        return tmp;
    }
}

signed main(){
    vector<string> hiragana;
    string s = "あ";
    hiragana.pb(s);
    while(s != "ん"){
        s[0]++;
        hiragana.pb(s);
    }
    rep(40) cout << hiragana[rand() % (int)hiragana.size()];
    ll n, p;
    cin >> n >> p;
    ll a[2] = {0, 0};
    rep(n){
        ll tmp;
        cin >> tmp;
        a[tmp%2]++;
    }
    ll ans = 0;
    if(p == 0){
        ll tmp = 0;
        if(a[1] >= 2) for(ll i=2;i<=a[1];i+=2){
            tmp += comb(a[1], i);
        }
        ans += pow(2, a[0]) * (tmp+1);
    }else{
        ll tmp = 0;
        for(ll i=1;i<=a[1];i+=2){
            tmp += comb(a[1],i);
        }
        ans += pow(2, a[0]) * tmp;
    }
    cout << ans;
    return 0;

}
