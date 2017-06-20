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
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	ll N, T, L;
	cin >> N >> L >> T;

	vector<ll> x(N), w(N), y(N);
	rep(N){
		cin >> x[i] >> w[i];
		if(w[i] == 1){
			y[i] = (x[i]+T)%L;
		}else{
			y[i] = ((x[i]-T)%L+L)%L;
		}
		cout << y[i] << endl;
	}

	ll cnt = 0;
	reppp(i, 1, N-1){
		if(w[i] == w[0]) continue;

		if(w[0] == 1 && w[i] == 2){
			double d = x[i] - x[0];
			if((double)T - d/2 > 0)
				cnt += (ll)((T-d/2) / (L/2) + 1);
		}else if(w[0] == 2 && w[i] == 1){
			double d = L - x[i] + x[0];
			if((double)T - d/2 > 0)
				cnt += (ll)((T-d/2) / (L/2) + 1);
		}
	}
	if(w[0] == 1) cnt %= N;
	else cnt = (N - cnt) % N;

	vector<ll> yy(y); sort(all(yy));
	rep(N){
		cout << yy[(cnt+i)%N]<< endl;
	}

}

