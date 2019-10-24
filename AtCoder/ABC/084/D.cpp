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
#define EPS 1e-9
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;

int main(){
    vector<int> v(100001, 0), fact(100001, 1);
    fact[0] = 0;
    fact[1] = 0;
    for(int i=2;i<=100000;i++){
        if(!fact[i]) continue;
        int j = 2*i;
        while(j <= 100000){
            fact[j] = 0;
            j += i;
        }
    }
    for(int i=3;i<=100000;i++){
        if(fact[i] && fact[(i+1)/2]) v[i] = 1;
        v[i] += v[i-1];
    }

    int q, l, r;
    cin >> q;
    rep(q){
        cin >> l >> r;
        cout << v[r]-v[l-1] << endl;
    }
}
