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
#define MOD 1000000007
#define MAX 100000
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

//int G[MAX][MAX];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a;

    cin >> n;
    if(n <= 2){
        cout << n << endl;
        return 0;
    }
    int m = 2, sum = 3;
    while(sum < n){
        m++;
        sum += m;
    }
    if(n == sum){
        reppp(j, 1, m){
            cout << j << endl;
        }
    }else if(n < sum){
        a = n;
        reppp(j, 1, m-2){
            cout << j << endl;
            a -= j;
        }
        cout << a << endl;
    }

    return 0;
}
