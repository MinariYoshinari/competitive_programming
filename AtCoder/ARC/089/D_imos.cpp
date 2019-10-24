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
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int n,k;
int black[4004][4004];

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int xx,yy;
    char cc;
    cin >> n >> k;
    
    int kk = 2*k;
    rep(n){
        cin >> xx >> yy >> cc;
        if(cc == 'W') xx = (xx + k);
        xx %= kk;
        yy %= kk;
        black[xx][yy]++;
        black[xx+kk][yy]++;
        black[xx][yy+kk]++;
        black[xx+kk][yy+kk]++;
        /*
        cout << yy << " " << xx << endl;
        for(int i=kk-1;i>=0;i--){
            repp(j, kk){
                printf("%3d", black[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
    }
    reppp(j, 1, 2*kk) black[0][j] += black[0][j-1];
    reppp(i, 1, 2*kk) black[i][0] += black[i-1][0];
    reppp(i, 1, 2*kk){
        reppp(j, 1, 2*kk){
            black[i][j] += black[i-1][j]+black[i][j-1]-black[i-1][j-1];
        }
    }
    /*
    for(int i=2*kk-1;i>=0;i--){
        repp(j, 2*kk){
            printf("%3d", black[i][j]);
        }
        printf("\n");
    }
    */
    

    int ans = 0;
    reppp(i, 1, kk+1){
        reppp(j, 1, kk+1){
            int tmp = black[i+k-1][j+k-1] - black[i-1][j+k-1] - black[i+k-1][j-1] + black[i-1][j-1];
            tmp += black[i+kk-1][j+kk-1] - black[i+k-1][j+kk-1] - black[i+kk-1][j+k-1] + black[i+k-1][j+k-1];
            // cout << tmp << endl;
            // printf("%d,%d = %d\n", i, j, tmp);
            ans = max(tmp, ans);
        }
    }
    cout << ans << endl;
}