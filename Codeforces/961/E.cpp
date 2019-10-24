#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

struct BIT{
    int n;
    int bit[1000001];
    BIT(int n){
        this->n = n;
        fill(bit, bit+n, 0);
    }

    void add(int idx, int x){
        for(int i=idx;i<=this->n;i+=i&-i) bit[i] += x;
    }

    //bit[1]からbit[end]までの和 (閉区間)
    int sum(int end){
        int ret = 0;
        for(int i=end;i>=1;i-=i&-i) ret += bit[i];
        return ret;
    }

    int count_swap(vector<int> v){
        int ret = 0;
        reppp(i, 1, n){
            add(v[i], 1);
            ret += i - sum(v[i]);
        }
        return ret;
    }
};

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    vector<int> b[n+1];
    reppp(i, 1, n+1){
        cin >> a[i];
        a[i] = min(n, a[i]);
        b[a[i]].push_back(i);
    }

    ll ans = 0;
    BIT tree = BIT(1<<18);
    for(int i=n;i>=1;i--){
        for(int bi: b[i]){
            tree.add(bi, 1);
        }

        if(i+1 <= a[i]) ans += tree.sum(a[i]) - tree.sum(i);
    }

    cout << ans << endl;
}
