#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

ll grundy(ll a, ll k){
    if(a % k == 0) return a/k;
    if(a == k+1) return 0;
    return grundy(a - (a/k+1) * max(1LL, (a%k) / (a/k+1)), k);
}

int main(){
    int n;
    cin >> n;
    ll a,k,g = 0LL;
    rep(n){
        cin >> a >> k;
        g = g ^ grundy(a, k);
    }

    cout << (g?"Takahashi":"Aoki") << endl;
}
