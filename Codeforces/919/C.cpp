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

int rows[2000], columns[2000];
string field[2000];

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    ll ans = 0;
    cin >> n >> m >> k;

    rep(n){
        cin >> field[i];
        repp(j, m){
            if(j == 0) rows[0] = (field[i][j] == '.');
            else{
                if(field[i][j] == '.'){
                    rows[j] = rows[j-1] + 1;
                }else{
                    rows[j] = 0;
                }
            }
            if(rows[j] >= k) ans++;
        }
    }

    if(k > 1) repp(j, m){
        rep(n){
            if(i == 0) columns[i] = (field[i][j] == '.');
            else{
                if(field[i][j] == '.'){
                    columns[i] = columns[i-1] + 1;
                    if(columns[i] >= k) ans++;
                }else{
                    columns[i] = 0;
                }
            }
        }
    }
    cout << ans << endl;
    
}
