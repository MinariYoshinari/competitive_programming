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
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	ll a,b,c;
	cin >>a >> b >> c;
	if(a == b && b == c && a % 2 == 0) cout << "-1";
	else{
		ll cnt = 0;
		while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
			ll aa = a/2, bb = b/2, cc = c/2;
			a = bb+cc;
			b = cc+aa;
			c = aa+bb;
			cnt++;
		}
		cout << cnt;
	}
}

