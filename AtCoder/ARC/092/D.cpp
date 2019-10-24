#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(n) cin >> a[i];
    rep(n) cin >> b[i];

    int ans = 0;
    repp(k, 29){
        vector<int> aa(n), bb(n);
        int t = 1 << k;
        rep(n) aa[i] = a[i] % (t << 1);
        rep(n) bb[i] = b[i] % (t << 1);
        sort(all(aa));
        sort(all(bb));

        int cnt = 0;
        rep(n){
            decltype(aa)::iterator start = lower_bound(all(aa),  t    -bb[i]);
            decltype(aa)::iterator end   = lower_bound(all(aa), (t<<1)-bb[i]);
            cnt += (int)(end-start);
            start = lower_bound(all(aa), (t<<1)+t-bb[i]);
            end   = lower_bound(all(aa), (t<<2)-bb[i]);
            cnt += (int)(end-start);
        }

        if(cnt & 1) ans |= 1 << k;
    }
    cout << ans << endl;
}