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

vector<ll> vectorize(ll n){
    vector<ll> ret;
    while(n){
        ret.push_back(n % 10);
        n /= 10;
    }
    return ret;
}

ll toll(vector<ll> v){
    ll base = 10LL, ret = 0LL;
    for(ll x: v){
        ret += x * base;
        base *= 10;
    }
    return ret;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> v = vectorize(n);

    ll anssum, ans;
    rep((int)v.size()){
        if(!i){
            anssum = accumulate(all(v), 0LL);
            ans = n;
            continue;
        }
        vector<ll> u(v);
        if(v[i] == 0){
            int j = i;
            while(u[j] == 0 && j < (int)u.size()) u[j++] = 9;
            if(j == (int)u.size()) continue;
            u[j]--;
            repp(k, i) u[k] = 9;
        }else{
            u[i]--;
            repp(k, i) u[k] = 9;
        }
        ll tmpsum = accumulate(all(u), 0LL);
        if(anssum < tmpsum){
            anssum = tmpsum;
            ans = toll(u);
        }
    }
    cout << anssum << endl;
}
