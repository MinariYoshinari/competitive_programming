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

vector<int> tovec(string s, int n){
    vector<int> v;
    rep(n){
        v.push_back((int)(s[i] - '0'));
    }
    return v;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    string sa, sb;
    cin >> sa >> sb;
    ll b_n = stoll(sb);
    int n = (int)sa.length();
    int m = (int)sb.length();
    vector<int> a = tovec(sa, n);
    vector<int> b = tovec(sb, m);

    vector<int> aa(10, 0);
    rep(m){
        aa[a[i]]++;
    }
    
    ll ans = 0;

    rep(n+1){
        vector<int> aaa(aa);
        ll tmp = 0;
        int j = 0, bj;
        while(j < i){
            bj = b[j];
            if(j == i-1) bj--;
            while(bj >= 0 && aaa[bj] == 0) bj--;
            if(bj < 0) break;
            tmp = tmp * 10LL + (ll)bj;
            aaa[bj]--;
            j++;
        }
        int mx = 9;
        while(j < n){
            while(mx >= 0 && aaa[mx] == 0) mx--;
            if(mx < 0) break;
            tmp = tmp * 10LL + (ll)mx;
            aaa[mx]--;
            j++;
        }
        if(mx < 0) continue;
        // cout << tmp << " " << b_n << endl;
        if(tmp <= b_n) ans = max(ans, tmp);
    }

    cout << ans << endl;
}