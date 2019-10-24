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
#define MAX 1001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

//int matrix[n][n];

signed main(){
    int r, c, n;
    cin >> r >> c >> n;
    vector<int> row(r, MOD), column(c, MOD);
    column[0] = 0;

    // 計算量削減してO(n)にできそう
    int rr, cc, aa;
    vector<tuple<int, int, int> > v(n);
    repp(k, n){
        cin >> rr >> cc >> aa;
        rr--; cc--;
        if(cc == 0) row[rr] = aa;
        if(rr == 0 && cc != 0) column[cc] = aa;
        v[k] = make_tuple(rr, cc, aa);
    }
    
    reppp(cc, 1, c-1){
        if(column[cc] != MOD) column[cc] -= row[0];
    }

    repp(k, n){
        rr = get<0>(v[k]);
        cc = get<1>(v[k]);
        aa = get<2>(v[k]);
        if(row[rr] != MOD && column[cc] != MOD){
            if(row[rr] + column[cc] != aa){
                cout << "No" << endl;
                return 0;
            }
        }else if(row[rr] == MOD){
            row[rr] = aa - column[cc];
        }else if(column[cc] == MOD){
            column[cc] = aa - row[rr];
        }
    }
    
    if(*min_element(all(row)) + *min_element(all(column)) < 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}