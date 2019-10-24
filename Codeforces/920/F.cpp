#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cassert>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<bitset>

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

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[n], maxa = 0;
    rep(n){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    b[0] = 0;
    rep(n) b[i+1] = a[i] + b[i];

    int c[maxa+1];
    c[1] = 1;
    reppp(i, 2, maxa+1){
        c[i] = 0;
        int j = 1;
        while(j*j < i){
            if(i % j == 0) c[i] += 2;
            j++;
        }
        if(j*j == i) c[i]++;
    }

    int t,l,r;
    repp(k, m){
        cin >> t >> l >> r;
        if(t == 1){
            reppp(i, l-1, r){
                a[i] = c[a[i]];
            }
            reppp(i, l-1, n) b[i+1] = a[i]+b[i];

        }else{
            cout << b[r]-b[l-1] << endl;
        }
    }
    return 0;
}