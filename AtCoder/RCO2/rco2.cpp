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
#include<random>

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

char itoc(int i){
	switch(i){
		case 0:
			return 'D';
		case 1:
			return 'U';
		case 2:
			return 'R';
		case 3:
			return 'L';
		default:
			return 'D';
	}
}

signed main(){
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand4(0, 4);  
  cin >> H >> W >> K >> sy >> sx;
  sy--; sx--;
  rep(50) cin >> ss[i];
  cin >> N;
vector<int> fy(N), fx(N); vector<ll> ff(N), dd(N);
  vector<P> d_sort; vector<bool> use(N, false);
  rep(N){
	cin >> fy[i] >> fx[i] >> ff[i] >> dd[i];
	d_sort.emplace_back(abs(sy- fy[i])+abs(sx - fx[i]), i);
	fy[i]--; fx[i]--;
  }

  int count = 0;
  while(!d_sort.empty()){
	sort(all(d_sort));  
	int i = d_sort[0].second;
	ll f = ff[i], d = dd[i];
	int gy = fy[i], gx = fx[i];

	int count_same = 0;
	char before = '-';
	while(sy != gy || sx != gx){
		char next = '-';
		if(sy < gy && sy < H-1 && ss[sy+1][sx] != '#'){
			next = 'D';
		}else if(sy > gy && sy > 0 && ss[sy-1][sx] != '#'){
			next = 'U';
		}else if(sx < gx && sx < W-1 && ss[sy][sx+1] != '#'){
			next = 'R';
		}else if(sx > gx && sx > 0 && ss[sy][sx-1] != '#'){
			next = 'L';
		}
		if(count_same > -1) next = '-';
		if(next == '-'){
			bool flag = true;
			do{
				int num = rand4(mt);
				next = itoc(num);
				if(next == 'D' && sy < H-1 && ss[sy+1][sx] != '#'){
					flag = false;
				}else if(next == 'U' && sy > 0 && ss[sy-1][sx] != '#'){
					flag = false;
				}else if(next == 'R' && sx < W-1 && ss[sy][sx+1] != '#'){
					flag = false;
				}else if(next == 'L' && sx > 0 && ss[sy][sx-1] != '#'){
					flag = false;
				}
			}while(flag);
		}
		cout << next;
		count++;
		if(next == before){
			count_same++;
		}else{
			count_same = 0;
		}
		before = next;
		if(count >= K) break;
	}
	if(count >= K) break;
	
	vector<P> d_sort2;
	fy[i] = -1;
	repp(j, N){
		if(fy[j] != -1)
			d_sort2.emplace_back(abs(sy- fy[j])+abs(sx - fx[j]), j);
	}
	swap(d_sort, d_sort2);
  }

  while(count < K){
	cout << '-';
	count++;
  }

}
