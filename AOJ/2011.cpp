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
#include<bitset>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
// #define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int main(){
    int n;
    while(scanf("%d", &n) && n != 0){
        int days[31][n];
        fill(days[0], days[31], 0);
        rep(n){
            int m;
            scanf("%d", &m);
            repp(j, m){
                int day;
                scanf("%d", &day);
                days[day][i] = 1;
            }
        }

        int ans = -1;
        bitset<50> people[n];
        rep(n){
            bitset<50> bs(0uL);
            bs.set(i);
            people[i] = bs;
        }
        reppp(i, 1, 31){
            bitset<50> bs(0uL);
            repp(p, n){
                if(days[i][p]) bs |= people[p];
            }
            if(bs.count() == n){
                ans = i;
                break;
            }
            repp(p, n){
                if(days[i][p]) people[p] = bs;
            }
        }
        printf("%d\n", ans);
        
    }
    return 0;
}
