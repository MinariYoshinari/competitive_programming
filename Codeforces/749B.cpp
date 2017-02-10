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
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
  vector<P> p;
  ll x,y;
  
  rep(3){
	scanf("%lld %lld", &x, &y);
	p.push_back(make_pair(x, y));
  }

  set<P> s;
  rep(3){
	int j = (i+1) % 3, k = (i+2) % 3;
	x = p[i].first + p[j].first - p[k].first;
	y = p[i].second + p[j].second - p[k].second;
	s.insert(make_pair(x, y));
	x = p[i].first - p[j].first + p[k].first;
	y = p[i].second - p[j].second + p[k].second;
	s.insert(make_pair(x, y));
  }

  printf("%d\n", (int)s.size());
  for(auto itr=s.begin(); itr !=s.end(); itr++){
	printf("%lld %lld\n", (*itr).first, (*itr).second);
  }
}
