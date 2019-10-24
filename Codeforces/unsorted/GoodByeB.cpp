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
  int n;
  scanf("%d", &n);

  int y = 0;
  rep(n){
	int t;
	char s[5];
	scanf("%d %s", &t, s);
	switch(s[0]){
	case 'S':
	  if(y == 20000 || y + t > 20000){
		printf("NO");
		return 0;
	  }else{
		y += t;
	  }
	  break;

	case 'N':
	  if(y == 0 || y - t < 0){
		printf("NO");
		return 0;
	  }else{
		y -= t;
	  }
	  break;

	case 'E':
	case 'W':
	  if(y == 0 || y == 20000){
		printf("NO");
		return 0;
	  }
	  break;

	default:
	  break;
	}
  }
  if(y == 0){
	printf("YES");
  }else{
	printf("NO");
  }
  return 0;
}
