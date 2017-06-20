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

  int previous = 0;
  rep(K){	
	if(sy-1 >= 0 && ss[sy-1][sx] != '#' && previous != 1){
	  cout << 'U';
	  previous = -1;
	  sy--;
	}else if(sy+1 < H && ss[sy+1][sx] != '#' && previous != -1){
	  cout << 'D';
	  previous = 1;
	  sy++;
	}else if(sx-1 >= 0 && ss[sy][sx-1] != '#' && previous != 2){
	  cout << 'L';
	  previous = -2;
	  sx--;
	}else if(sx+1 < W && ss[sy][sx+1] != '#' && previous != -2){
	  cout << 'R';
	  previous = 2;
	  sx++;
	}else{
	  	if(sy-1 >= 0 && ss[sy-1][sx] != '#'){
		  cout << 'U';
		  previous = -1;
		  sy--;
		}else if(sy+1 < H && ss[sy+1][sx] != '#'){
		  cout << 'D';
		  previous = 1;
		  sy++;
		}else if(sx-1 >= 0 && ss[sy][sx-1] != '#'){
		  cout << 'L';
		  previous = -2;
		  sx--;
		}else if(sx+1 < W && ss[sy][sx+1] != '#'){
		  cout << 'R';
		  previous = 2;
		  sx++;
		}else{
		  cout << '-';
		}
	}
  }
  
  
}
