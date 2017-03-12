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
#define coordinates(x,y) cout << x << " " << y << endl;
 
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
struct edge{int from, to; ll cost;};

int input[50][50];
vector< vector<bool> > use;
vector<P> output;

bool search(int x, int y){
  vector<P> tmp_out; int n = 0;
  priority_queue< pair<int,P> > q;
  vector< vector<bool> > use_copy(use);

  q.push(make_pair(input[y][x], make_pair(x, y)));
 
  while(!q.empty()){
	auto t = q.top(); q.pop();
	P p = t.second;
	int xx = p.first, yy = p.second;

	if(use_copy[yy][xx]) continue;
	
	tmp_out.push_back(p);
	n++;
	if(n == 8){
	  rep(8){
		P tmp = tmp_out[i];
		output.push_back(tmp);
		//if(use[tmp.second][tmp.first]) coordinates(tmp.first, tmp.second);
	    use[tmp.second][tmp.first] = true;
	  }
	  return true;
	}
	
	use_copy[yy][xx] = true;
	if(yy < 49 && !use_copy[yy+1][xx] && input[yy+1][xx] != 0){
	  q.push(make_pair(input[yy+1][xx], make_pair(xx, yy+1)));
	}
	if(xx < 49 && !use_copy[yy][xx+1] && input[yy][xx+1] != 0){
	  q.push(make_pair(input[yy][xx+1], make_pair(xx+1, yy)));
	}
	if(yy > 0 && !use_copy[yy-1][xx] && input[yy-1][xx] != 0){
	  q.push(make_pair(input[yy-1][xx], make_pair(xx, yy-1)));
	}
	if(xx > 0 && !use_copy[yy][xx-1] && input[yy][xx-1] != 0){
	  q.push(make_pair(input[yy][xx-1], make_pair(xx-1, yy)));
	}
  }
  
  return false;
}


signed main(){
  int c = 0;
  use = vector< vector<bool> >(50, vector<bool>(50, false));

  string s;
  rep(3) cin >> s;
  rep(50){
	cin >> s;
	repp(j, 50){
	  input[i][j] = s[j] - '0';
	}
  }
  
  repp(x, 50){
	repp(y, 50){
	  if(!use[y][x] && input[y][x] != 0){
		if(search(x, y)) c++;
	  }
	}
  }
  cout << c << endl;
  rep(c*8){
	cout << output[i].second+1 << " " << output[i].first+1 << endl;
  }
}
