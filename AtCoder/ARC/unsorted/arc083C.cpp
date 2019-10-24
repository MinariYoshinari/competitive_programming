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
#define MOD 100007
#define MAX 100001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    int water = a, sugar = 0, water_tmp, sugar_tmp;
    repp(ai, f/100+1){
        repp(bi, f/100+1){
            water_tmp = a*ai+b*bi;
            if(water_tmp * 100 > f || water_tmp == 0) break;
            repp(ci, e*water_tmp/c+1){
                repp(di, e*water_tmp/d+1){
                    sugar_tmp = c*ci+d*di;
                    if(sugar_tmp + water_tmp*100 > f || sugar_tmp > e*water_tmp) break;
                    if(sugar * water_tmp < sugar_tmp * water){
                        sugar = sugar_tmp;
                        water = water_tmp;
                    }
                }
            }
        }
    }
    
    printf("%d %d\n", water*100+sugar, sugar);

}
