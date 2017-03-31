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
	ll N, M;
	cin >> N >> M;
	vector<P> a(N), c(M);
	ll x, y;
	rep(N){
		cin >> x >> y;
		a.emplace_back(x,y);
	}
	rep(M){
		cin >> x >> y;
		c.emplace_back(x,y);
	}
	rep(N){
		int min_i = -1;
		ll min_d = MAX;
		repp(j, M){
			if(abs(a[i].first - c[j].first) + abs(a[i].second - c[j].second) < min_d){
				min_d = abs(a[i].first - c[j].first) + abs(a[i].second - c[j].second);
				min_i = j;
			}
			cout << min_d <<  "a" << endl;
		}
		cout << min_i+1 << endl;
	}

}

