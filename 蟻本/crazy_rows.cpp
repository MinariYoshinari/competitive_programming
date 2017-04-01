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
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	ll N;
	cin >> N;
	vector<string> m(N);
	vector<ll> a(N);
	rep(N){
		cin >> m[i];
		for(int j=N-1;j>=0;j--){
			if(m[i][j] == '1'){
				a[i] = j;
				break;
			}
		}
	}
	ll ans = 0;
	rep(N-1){
		ll j = i;
		while(a[j] > i) j++;
		if(i == j) continue;
		ans += j - i;
		for(int k = j; k > i; k--){
			swap(m[k], m[k-1]);
			swap(a[k], a[k-1]);
		}
	}
	cout << ans;
}

