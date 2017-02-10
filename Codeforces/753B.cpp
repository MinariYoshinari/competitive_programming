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
  ll n;
  scanf("%lld", &n);

  ll X = 1234567, Y = 123456, Z = 1234;
  //これ貪欲にやっちゃだめなやつだ
  while(n > 0){
	if(n >= X){
	  n -= n/X * X;
	}else if(n >= Y){
	  n -= n/Y * Y;
	}else if(n >= Z){
	  n -= n/Z * Z;
	}else{
	  printf("NO");
	  return 0;
	}
	printf("%lld\n", n);
  }
  printf("YES");
  return 0;
}
