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

char patterns[4][2] = {{'R', 'Y'}, {'B', 'G'}, {'Y', 'R'}, {'G', 'B'}};

signed main(){
    int h, w, d;
    cin >> h >> w >> d;

    map<int, map<int, char> > mp;
    reppp(i, 1-h, w-1){
        int p = ((i-(1-h))/d) % 4;
        reppp(j, 0, w+h-2){
            mp[i][j] = patterns[p][(j/d) % 2];
            //cout << mp[i][j];
        }
        //cout << endl;
    }

    repp(y, h){
        repp(x, w){
            cout << mp[x-y][x+y];
        }
        cout << endl;
    }

    return 0;
}