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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
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

int n;
vector< vector< vector<int> > > a(2, vector< vector<int> >(51, vector<int>(51, 0)));
vector<int> d(51, 0);

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    if(n==1){
        int d;
        cin >> d;
        cout << d << endl;
        return 0;
    }
    if(n+1 >= 24){
        cout << 0 << endl;
        return 0;
    }

    
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
    // vectorの要素はd,i,j,k の順

    reppp(i, 1, n){
        cin >> d[i];
        repp(j, i){
            int dd = abs(d[i]-d[j]);
            dd = min(dd, 24-dd);
            que.push(vector<int>{dd, 0, j, i});
            dd = abs(24-d[i]-d[j]);
            dd = min(dd, 24-dd);
            que.push(vector<int>{dd, 1, j, i});
        }
    }

    int ans;
    while(true){
        vector<int> v = que.top(); que.pop();
        // rep(4) cout << v[i] << " ";
        // cout << endl;
        a[v[1]][v[2]][v[3]] = 1;
        if(a[1-v[1]][v[2]][v[3]]){
            ans = v[0];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}