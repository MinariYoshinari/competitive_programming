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
#define Pdd pair<double, double>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string tmpa,tmpb;
    cin >> tmpa >> tmpb;
    int n = (int)tmpa.length();
    vector<int> a(n), b(n);
    int only_zeroa = 1, only_zerob = 1;
    rep(n){
        a[i] = tmpa[i] - '0';
        if(only_zeroa && a[i]) only_zeroa = 0;
        b[i] = tmpb[i] - '0';
        if(only_zerob && b[i]) only_zerob = 0;
    }
    if(only_zerob){
        if(only_zeroa){
            cout << 0;
        }else{
            cout << -1;
        }
        return 0;
    }

    repp(d, n){
        int cnt = 0;
        repp(i, n){
            if(a[i] == b[(i+d)%n]) continue;
            cnt++;
            if(find(b.begin()+min(i, (i+d)%n), b.begin()+max(i, (i+d)%n), 1)+1 == b.begin()+max(i, (i+d)%n), 1)){
                
            }
    }
    return 0;
}
