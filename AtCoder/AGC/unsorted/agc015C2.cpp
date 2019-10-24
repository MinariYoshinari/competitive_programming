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
	ll N, M, Q;
	cin >> N >> M >> Q;
	vector< vector<ll> > edges_row(N, vector<ll>(M, 0)), edges_line(N, vector<ll>(M, 0));
	vector< vector<ll> > nodes(N, vector<ll>(M, 0));
	vector<string> s(N);
	rep(N){
		cin >> s[i];
		repp(j, M){
			if(s[i][j] == '1'){
				if(i == 0 && j == 0){
					nodes[0][0] = 1;
				}else if(j == 0){
					nodes[i][0] = nodes[i-1][0] + 1;
				}else{
					nodes[i][j] = nodes[i][j-1] + 1;
					if(i > 0) nodes[i][j] += nodes[i-1][j] - nodes[i-1][j-1];
				}
			}else{
				if(i > 0 && j == 0){
					nodes[i][0] = nodes[i-1][0];
				}else{
					if(i > 0){
						nodes[i][j] = nodes[i-1][j];
					}
					if(j > 0){
						nodes[i][j] += nodes[i][j-1];
						if(i>0){
							nodes[i][j] -= nodes[i-1][j-1];
						}
					}
				}
			}
		}
	}

	rep(N){
		reppp(j, 1, M-1){
			if(s[i][j] == '1' && s[i][j-1] == '1'){
				edges_line[i][j] = edges_line[i][j-1] + 1;
			}else{
				edges_line[i][j] = edges_line[i][j-1];
			}
		}
	}

	reppp(i, 1, N-1){
		repp(j,M){
			edges_line[i][j] += edges_line[i-1][j];

			if(s[i][j] == '1' && s[i-1][j] == '1'){
				edges_row[i][j] = edges_row[i-1][j] + 1;
			}else{
				edges_row[i][j] = edges_row[i-1][j];
			}
		}
	}

	reppp(j, 1, M-1){
		rep(N){
			edges_row[i][j] += edges_row[i][j-1];
		}
	}

	rep(Q){		
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		x--;y--;xx--;yy--;
		ll n_nodes = nodes[xx][yy];
		ll n_edges = edges_row[xx][yy] + edges_line[xx][yy];
		if(x > 0){
			n_nodes -= nodes[x-1][yy];
			n_edges += edges_line[x-1][y]- edges_line[x-1][yy];
		}
		n_edges -= edges_row[x][yy];
	
		if(y > 0){
			n_nodes -= nodes[xx][y-1];
			n_edges += edges_row[x][y-1] - edges_row[xx][y-1];
		}
		n_edges -= edges_line[xx][y];
		
		if(x > 0 && y > 0){
			n_nodes += nodes[x-1][y-1];
		}
		cout << n_nodes << " " << n_edges << endl;
		cout << n_nodes - n_edges << endl;
	}
}
