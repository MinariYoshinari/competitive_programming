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
	vector<ll> a(3*N), b(3*N);
	cin >> a[0];
	b[0] = a[0];
	reppp(i, 1, 3*N-1){
		ll tmp;
		cin >> tmp;
		b[i] = tmp + b[i-1];
		a[i] = tmp;
	}

	ll large = b[N-1], small = b[3*N-1] - b[2*N-1];
	int large_i = N-1, small_i = 2*N;
	repp(k, N){
		auto large_min_i = min_element(a.begin(), a.begin() + (large_i+1));
		auto small_max_i = max_element(a.begin()+small_i, a.end()); 
		ll large_min = *large_min_i;
		ll small_max = *small_max_i;
		if(a[large_i+1] - large_min > small_max - a[small_i-1]){
			large = large - large_min + a[large_i+1];
			large_i++;
			*large_min_i = 1e10;
		}else{
			small = small - small_max + a[small_i-1];
			small_i--;
			*small_max_i = 0;
		}
	}
	ll ans = large - small;

	large = b[N-1], small = b[3*N-1] - b[2*N-1];
	large_i = N-1, small_i = 2*N;
	repp(k, N){
		auto large_min_i = min_element(a.begin(), a.begin() + (large_i+1));
		auto small_max_i = max_element(a.begin()+small_i, a.end()); 
		ll large_min = *large_min_i;
		ll small_max = *small_max_i;
		if(a[large_i+1] - large_min >= small_max - a[small_i-1]){
			large = large - large_min + a[large_i+1];
			large_i++;
			*large_min_i = 1e10;
		}else{
			small = small - small_max + a[small_i-1];
			small_i--;
			*small_max_i = 0;
		}
	}
	cout << max(ans, large - small);
}


