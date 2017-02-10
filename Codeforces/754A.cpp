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
  int  n;

  scanf("%d", &n);
  
  ll a[n], sum = 0;
  rep(n){
	scanf("%lld", &a[i]);
	sum += a[i];
  }

  if(sum != 0){
	printf("YES\n");
	printf("1\n");
	printf("%d %d\n", 1, n);
	return 0;
  }

  sum = 0;
  vector<int> start;
  bool flag = false;
  start.push_back(1);
  rep(n-1){
	sum += a[i];
	if(sum != 0 && a[i+1] != 0){
	  start.push_back(i+1 + 1);
	  sum = 0;
	  flag = true;
	}
  }

  if(!flag){
	printf("NO\n");
	return 0;
  }
  
  int m = (int)start.size();
  printf("YES\n");
  printf("%d\n", m);
  rep(m-1){
	printf("%d %d\n", start[i], start[i+1]-1);
  }
  printf("%d %d\n", start[m-1], n);

  return 0;
}
