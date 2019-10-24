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
	int N;
	cin >> N;
	vector<ll> a(3*N), large_a(N+1), small_a(N+1);
	priority_queue<ll> large, small;
	large_a[0] = 0; small_a[0] = 0;
	rep(3*N){
		cin >> a[i];
		if(i < N) large_a[0] += a[i];
		else if(2*N <= i) small_a[N] += a[i];
	}
	rep(N){
		large.push(-a[i]);
		small.push(a[3*N-1-i]);
	}

	reppp(i, N, 2*N-1){
		large.push(-a[i]);
		ll tmp = large.top();large.pop();
		large_a[i-N+1] = large_a[i-N] + a[i] + tmp;
	}
	for(int i=2*N-1; i>=N; i--){
		small.push(a[i]);
		ll tmp = small.top();small.pop();
		small_a[i-N] = small_a[i-N+1] + a[i] - tmp;
	}

	vector<ll> ans(N+1);
	rep(N+1){
		cout << large_a[i] << " " << small_a[i] << endl;
		ans[i] = large_a[i] -  small_a[i];
	}
	cout << *max_element(all(ans));
}
