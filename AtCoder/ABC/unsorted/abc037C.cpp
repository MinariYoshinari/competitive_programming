#include<cstdio>
#include<iostream>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define pb(x) push_back(x)
using namespace std;

typedef long long ll;

signed main(){
    ll N, K, ans = 0;
    scanf("%lld %lld", &N, &K);
    ll a[N];
    if(K > N/2) K = N - K + 1;
    rep(N){
        ll tmp;
        scanf("%lld", &tmp);
        a[i] = tmp;
        if(i < K){
            ans += tmp * (ll)(i+1);
        }else if(N-i >= K){
            ans += tmp * K;
        }else{
            ans += tmp * (N-(ll)i);
        }
    }
    printf("%lld", ans);
}
