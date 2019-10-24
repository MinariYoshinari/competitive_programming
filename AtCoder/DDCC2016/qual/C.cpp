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
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

signed main(){
    ll n,k;
    cin >> n >> k;

    if(k == 1){
        cout << n*(n-1)/2 << endl;
        return 0;
    }

    map<ll, ll> a;

    rep(n){
        ll tmp;
        cin >> tmp;
        a[gcd(k, tmp)]++;
    }

    ll ans = 0;
    for(auto itr1=a.begin();itr1!=a.end();++itr1){
        ll n1 = itr1->first;
        for(auto itr2=itr1;itr2!=a.end();++itr2){
            ll n2 = itr2->first;
            if((n1 * n2) % k == 0){
                if(n1 == n2){
                    ans += (itr1->second) * ((itr1->second)-1) / 2;
                }else{
                    ans += (itr1->second) * (itr2->second);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
