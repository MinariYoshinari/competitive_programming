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

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(n){
        cin >> a[i];
        b[i] = abs(a[i]);
    }
    int maxi = (int)(max_element(all(b)) - b.begin());

    int cnt = n-1;
    vector<Pii> ans;
    if(*max_element(all(a)) * (*min_element(all(a))) <= 0){
        cnt += n-1;
        rep(n){
            if(i == maxi)continue;
            ans.emplace_back(maxi+1, i+1);
        }
    }
    if(a[maxi] > 0){
        rep(n-1) ans.emplace_back(i+1, i+2);
    }else{
        for(int i=n-2;i>=0;i--) ans.emplace_back(i+2, i+1);
    }
    
    cout << cnt << endl;
    for(Pii p: ans){
        cout << p.first << " " << p.second << endl;
    }

}