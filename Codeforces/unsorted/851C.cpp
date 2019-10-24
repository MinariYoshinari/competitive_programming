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
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("1\n1");
        return 0;
    }else if(n == 2){
        printf("2\n1\n2");
        return 0;
    }
    int v[n][5], edges[n][n][5];
    rep(n){
        repp(j, 5) scanf("%d", &v[i][j]);
        repp(j, i){
            repp(k, 5){
                edges[i][j][k] = v[j][k] - v[i][k];
                edges[j][i][k] = -edges[i][j][k];
            }
        }
    }

    int good = 0;
    vector<int> idx;
    if(n <= 11){
        rep(n){
            int flag = 1;
            repp(j1, n-1){
                if(i == j1) continue;
                reppp(j2, j1+1, n-1){
                    if(i == j2) continue;
                    int product = 0;
                    repp(k, 5){
                        product += edges[i][j1][k] * edges[i][j2][k];
                        //printf("%d * %d\n", edges[i][j1][k], edges[i][j2][k]);
                    }
                    //printf("edges[%d][%d] * edges[%d][%d] = %d\n", i, j1, i, j2, product);
                    if(product > 0) flag = 0;
                }
                if(!flag) break;
            }
            if(flag){
                good++;
                idx.pb(i+1);
                flag = 1;
                break;
            }
        }
    }

    printf("%d\n", good);
    for(int i: idx) printf("%d\n", i);
    return 0;
}
