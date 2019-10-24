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
#define EPS 1e-9
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, p;
    vector<int> v;
    while(true){
        cin >> n;
        if(n == 0) break;
        
        rep(n){
            cin >> p;
            v.push_back(p);
        }
        sort(all(v));
        cout << accumulate(v.begin()+1, v.end()-1, 0) / (n-2) << endl;
        v.clear();
    }
}
