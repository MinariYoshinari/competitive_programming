#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<tuple>
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
#define coordinates(x,y) cout << x << " " << y << endl
#define distance(ax, ay, bx, by) abs(ax-bx) + abs(ay-by)
 
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
struct edge{int from, to; ll cost;};


int H, W, K, sy, sx, N;
vector<string> ss(50);

signed main(){
  cin >> H >> W >> K >> sy >> sx;
  sy--; sx--;
  rep(50) cin >> ss[i];
  cin >> N;
  vector<int> fy(N), fx(N); vector<ll> ff(N), dd(N);
  vector<P> d_sort(N); vector<bool> use(N, false);
  rep(N){
	cin >> fy[i] >> fx[i] >> ff[i] >> dd[i];
	d_sort[i] =  make_pair(dd[i], i);
	fy[i]--; fx[i]--;
  }
  sort(all(d_sort));

  for(int i=N-1;i>=0;i--){
	int i_food = d_sort[i].second;

	if(use[i_food]) continue;
	
	int count = 0;
	char previous = 'E';
	while(count <= 5){
	  bool flag = false;
	  repp(j, N){
		if(sy == fy[j] && sx == fx[j]){
		  use[j] = true;
		  if(i == j) flag = true;
		}
	  }
	  if(flag) break;
	  count++;
	  priority_queue< pair<int, char> > que;
		if(sy-1 >= 0 && ss[sy-1][sx] == '.' && previous != 'D'){
		  que.push(make_pair(-distance(fy[i_food], fx[i_food], sy-1, sx), 'U'));
		}
		if(sy+1 < 50 && ss[sy+1][sx] == '.'){
		  que.push(make_pair(-distance(fy[i_food], fx[i_food], sy+1, sx), 'D'));
		}
		if(sx-1 >= 0 && ss[sy][sx-1] == '.' && previous != 'R'){
		  que.push(make_pair(-distance(fy[i_food], fx[i_food], sy, sx-1), 'L'));
		}
		if(sx+1 < 50 && ss[sy][sx+1] == '.'){
		  que.push(make_pair(-distance(fy[i_food], fx[i_food], sy, sx+1), 'R'));
		}

		auto top = que.top();
		cout << top.second;
		previous = top.second;
		switch(top.second){
		case 'U':
		  sy--;
		  break;
		case 'D':
		  sy++;
		  break;
		case 'L':
		  sx--;
		  break;
		case 'R':
		  sx++;
		  break;
		default:
		  break;
		}
	}
	use[i_food] = true;
  }
  
  
}
