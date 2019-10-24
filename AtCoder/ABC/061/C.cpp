#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(n) for(ll i=0;i<n;i++)
#define Pll std::pair<ll, ll>
#define all(v) v.begin(), v.end()

typedef long long ll;

int main(){
    ll length = 0, n, k;
    scanf("%lld %lld", &n, &k);
    std::vector<Pll> v(n);
    rep(n) scanf("%lld %lld", &v[i].first, &v[i].second);
    std::sort(all(v));
    for(Pll p: v){
        if(length < k && k <= length+p.second){
            printf("%lld\n", p.first);
            return 0;
        }
        length += p.second;
    }
}
