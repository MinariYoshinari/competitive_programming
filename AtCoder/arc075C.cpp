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
    int N, sum = 0;
    cin >> N;
    vector<int> s(N);
    priority_queue<int, vector<int>, greater<int> > que;

    rep(N){
        cin >> s[i];
        sum += s[i];
        if(s[i] % 10 != 0) que.push(s[i]);
    }
    if(sum % 10 == 0 && !que.empty()){
        int t = que.top();  que.pop();
        sum -= t;
    }
    if(sum % 10 == 0){
        cout << 0;
    }else{
        cout << sum;
    }
}