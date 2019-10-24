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
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	int N, M, Q;
	cin >> N >> M >> Q;
	vector< vector<bool> > s(N, vector<bool>(M, false));
	rep(N){
		string tmp;
		cin >> tmp;
		repp(j, M){
			if(tmp[j] == '1'){
				s[i][j] = true;
			}
		}
	}

	int x,y,xx,yy;
	repp(k, Q){
		cin >> x >> y >> xx >> yy;
		x--; y--; xx--; yy--;
		ll ans = 0;
		vector< vector<ll> > ss(xx-x+1, vector<ll>(yy-y+1, 0));
		reppp(i, x, xx){
			reppp(j, y, yy){
				if(s[i][j]){
					if((i-x > 0 && s[i-1][j]) || (j-y > 0 && s[i][j-1])){
						ss[i-x][j-y] = INF;
						if(i-x > 0 && s[i-1][j] && ss[i-x-1][j-y] != 0) ss[i-x][j-y] = ss[i-x-1][j-y];
						if(j-y > 0 && s[i][j-1] && ss[i-x][j-y-1] != 0){
							ss[i-x][j-y] = min(ss[i-x][j-y], ss[i-x][j-y-1]);
						}
						if(i-x > 0 && s[i-1][j]){
							ss[i-x-1][j-y] = min(ss[i-x-1][j-y],ss[i-x][j-y]);
						}
						if(j-y > 0 && s[i][j-1]){
							ss[i-x][j-y-1] = min(ss[i-x][j-y-1], ss[i-x][j-y]);
						}
					}else if(ss[i-x][j-y] == 0){
						ans++;
						ss[i-x][j-y] = ans;
					}
				}
			}
		}

		set<ll> st, del;
		repp(i, xx-x+1){
			repp(j, yy-y+1){
				if(ss[i][j] > 0){
					st.insert(ss[i][j]);
					if(i != 0 && ss[i-1][j] > 0 && ss[i-1][j] != s[i][j]){
						del.insert(ss[i-1][j]);
					}
					if(j != 0 && ss[i][j-1] > 0 && ss[i][j-1] != s[i][j]){
						del.insert(ss[i][j-1]);
					}
				}
			}
		}
		for(auto itr=del.begin();itr!=del.end();itr++) cout << *itr << endl;
		cout << endl;
	}
}
