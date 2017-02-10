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
#define MOD 1000000007
#define MAX 100000
#define INF 1410065408

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

priority_queue<P, vector<P>, greater<P> > que;
bool used[MAX];

signed main(){
  int n;
  ll a, b;
  scanf("%d %lld %lld", &n, &a, &b);
  
  ll before, after, cost = 0;
  scanf("%lld", &after);
  rep(n-1){
	before = after;
	scanf("%lld", &after);
	cost += min(b, a*(after-before));
  }

  printf("%lld", cost);
}
