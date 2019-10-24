#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);

    if(n % 2 == 0){
        rep(n){
            int tmp;
            cin >> tmp;
            if(i % 2 == 0){
                a[n/2 + i/2] = tmp;
            }else{
                a[n/2 - (i+1)/2] = tmp;
            }
        }
    }else{
        int tmp;
        cin >> tmp;
        a[(n-1)/2] = tmp;
        reppp(i, 1, n-1){
            int tmp;
            cin >> tmp;
            if(i % 2 == 0){
                a[(n-1)/2 - i/2] = tmp;
            }else{
                a[(n-1)/2 + (i+1)/2] = tmp;
            }
        }
    }
    rep(n-1){
        cout << a[i] << " ";
    }
    cout << a.back();
}