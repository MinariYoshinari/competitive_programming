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
    int n;
    cin >> n;
    int a[n];
    rep(n) cin >> a[i];
    string s;
    cin >> s;
    int b[n-1];
    rep(n-1) b[i] = (s[i] == '1');

    int ans = 1, i = 0;
    while(i < n){
        if(b[i] == 0){
            if(a[i] == i+1){
                i++;
                continue;
            }else{
                ans = 0;
                break;
            }
        }else{
            int j = i;
            while(j < n && b[j]) ++j;
            reppp(k, i, min(n, j+1)){
                if(a[k] < i+1 || j+1 < a[k]){
                    ans = 0;
                    break;
                }
            }
            i = j+1;
            if(!ans) break;
        }
    }
    cout << (ans?"YES":"NO") << endl;
}
