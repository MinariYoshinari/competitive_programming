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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	int N;
	cin >> N;
	vector<P> win(N+1, P(0, 0));
	map<ll, vector<ll> > mp;

	win[1].second = 1;
	reppp(i, 2, N){
		int p;
		cin >> p;
		win[i].first = i;
		win[p].second++;
	}
	sort(all(win));
	reppp(i, 1, N) cout << win[i].first << " " << win[i].second << endl;
}
