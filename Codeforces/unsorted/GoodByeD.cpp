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
  int t[n];
  rep(n){
	scanf("%d", &t[i]);
  }

  queue< pair<int, int> > que;
  bool use[150][150];
  fill(use[0], use[150] , false);
  que.push(make_pair(0, t[0]-1));
  rep(t[0]){
	use[0][i] = true;
  }
  int ans = 0;
  ans += t[0];
  reppp(i, 1, n-1){
	while(!que.empty()){
		pair<int, int> p = que.front(), q; que.pop();
		if(i % 2 == 0){
		  q = make_pair(p.first+t[i], p.second);
		  que.push(q);
		  q = make_pair(p.first, p.second+t[i]);
		  que.push(q);
		  reppp(j, 1, t[1]){
			printf("(%d, %d)\n", p.first+j, p.second);
			if(use[p.first+j][p.second]){
			  ans--;
			}else{
			  use[p.first+j][p.second] = true;
			}
			printf("(%d, %d)\n", p.first, p.second+j);
			if(use[p.first][p.second+j]){
			  ans--;
			}else{
			  use[p.first][p.second+j] = true;
			}
		  }
		}else{
		  if(p.first != 0){
			q = make_pair(abs(p.first-t[i]), p.second+t[i]);
			que.push(q);
		  }
		  q = make_pair(p.first+t[i], p.second+t[i]);
		  que.push(q);
		  reppp(j, 1, t[1]){
			if(p.first != 0){
			  printf("(%d, %d)\n", abs(p.first-j), p.second+j);
			  if(use[abs(p.first-j)][p.second+j]){
				ans--;
			  }else{
				use[abs(p.first-j)][p.second] = true;
			  }
			}
			printf("(%d, %d)\n", p.first+j, p.second+j);
			if(use[p.first+j][p.second+j]){
			  ans--;
			}else{
			  use[p.first+j][p.second+j] = true;
			}
		  }
		}

		ans += 2 * t[i];
		printf("%d\n", ans);
	}
  }

  printf("%d", ans);
  
  return 0;
}
