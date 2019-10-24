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
    int N, max;
    cin >> N;
    vector< vector<int> > a(N, vector<int>(N));
    // i列（行）目にjがあるか
    vector< map<int, int> > line(N), row(N);
    rep(N){
        repp(j, N){
            cin >> a[i][j];
            if(max < a[i][j]) max = a[i][j];
            line[i][a[i][j]] = 1;
            row[j][a[i][j]] = 1;
        }
    }
    int yes = 1;
    int ok;
    rep(N){
        repp(j, N){
            int m = a[i][j];
            if(m == 1) continue;
            ok = 0;
            for(auto itr=line[i].begin(); itr!=line[i].end();itr++){
                if(itr->first * row[j][m-(itr->first)]){
                    ok = 1;
                    break;
                }
            }
            if(ok == 0){
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
    return 0;

}
