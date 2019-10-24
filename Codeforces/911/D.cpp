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
struct edge{int from, to; ll cost;};

int N;
int bit[1000001];

void clear(){
    rep(N+1){
        bit[i] = 0;
    }
}

void update(int index, int value){
    for(int i=index; i <= N; i += i & -i){
        bit[i] += value;
    }
}

//sum bit[1]~bit[back_index]
int calc_sum(int back_index){
    int sum = 0;
    for(int i=back_index; i >= 1; i -= i & -i){
        sum += bit[i];
    }
    return sum;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m, ans = 0;
    cin >> n;
    N = n;
    vector<int> v(n+1);
    rep(n) cin >> v[i+1];
    cin >> m;
    reppp(i, 1, n){
        update(v[i], 1);
        ans += i - calc_sum(v[i]);
    }
    repp(k, m){
        int l,r;
        cin >> l >> r;
        repp(i, (r-l+1)/2){
            swap(v[l+i], v[r-i]);
        }
        
        ans = ans + (r-l) * (r-l+1) / 2;
        cout << ((ans%2)?"odd":"even") << endl;
        
    }
}