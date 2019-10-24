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

int not_prime[31625];

vector<ll> factorize(ll n){
    vector<ll> ret;
    ll i = 2, rt = sqrt(n);
    while(n != 1 && i <= rt){
        if(not_prime[i]){
            i++;
            continue;
        }
        ll j = i;
        while(j <= rt){
            not_prime[j] = 1;
            j += i;
        }

        while(n % i == 0){
            n /= i;
            ret.push_back(i);
        }

        i++;
    }
    if(n != 1){
        ret.push_back(n);
    }
    return ret;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    vector<ll> v = factorize(2592);
    for(ll x: v){
        cout << x << endl;
    }

}
