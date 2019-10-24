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
#include<numeric>

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
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,f,k, ans = 0;
    cin >> a >> b >> f >> k;
    
    if(k == 1){
        if(b < max(f, a-f)){
            cout << -1;
            return 0;
        }
    }else if(k == 2){
        if(b < f || b < 2*(a-f)){
            cout << -1;
            return 0;
        }
    }else if(b < 2*max(f, a-f)){
        cout << -1;
        return 0;
    }

    int tank = b;

    repp(kk, k-1){
        //cout << tank << " ";
        if(kk % 2 == 0){
            if(tank-a < a-f){
                ans++;
                tank = b - (a-f);
            }else{
                tank -= a;
            }
        }else{
            if(tank-a < f){
                ans++;
                tank = b - f;
            }else{
                tank -= a;
            }
        }
        //cout << tank << endl;
        //cout << kk <<  " " << ans << endl;
    }

    if(tank < a) ans++;

    cout << ans << endl;

    return 0;
}
