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

int n, k;
vector<int> v(200002, 0);

int rec(int low, int high, int idx){
    printf("call rec(%d, %d, %d)\n", low, high, idx);
    if(idx > k-1) return 1;
    if(v[idx] < low || high < v[idx]) return 0;
    if(low == high && low == v[idx]) return 1;
    int m = *max_element(v.begin(), v.begin()+idx+1);
    
    int ret = 1;
    if(v[idx] > low){
        ret &= rec(low, v[idx]-1, idx+1);
    }
    if(v[idx] < high){
        ret &= rec(v[idx]+1, high, m);
    }
    printf("rec(%d, %d, %d) = %d\n", low, high, idx, ret);
    return ret;
}

int main(){
    cin >> n >> k;
    vector<int> used(n+1, 0);
    rep(k){
        cin >> v[i];
        used[v[i]] = 1;
    }

    if(rec(1, n, 0)){
        rep(k) cout << v[i] << " ";
        int used_i = 1, used_j = -1;
        reppp(i, k, n-1){
            if(used_i > used_j){
                while(used_i < n && used[used_i]) used_i++;
                used_j = used_i;
                while(used_j <= n && !used[used_j]) used_j++;
                used_j--;
            }
            cout << used_j <<  " ";
            used[used_j--] = 1;
        }
    }else{
        cout << -1;
    }
}
