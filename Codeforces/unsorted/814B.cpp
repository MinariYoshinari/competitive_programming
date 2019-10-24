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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(n) cin >> a[i];
	rep(n) cin >> b[i];

	vector<int> ans(n);
	vector<bool> use(n+1, false);
	vector<int> zero;
	rep(n){
		if(a[i] == b[i]){
			ans[i] = a[i];
			use[a[i]] = true;
		}else{
			ans[i] = 0;
			zero.pb(i);
		}
	}
	
	if((int)zero.size() == 1){
		reppp(i, 1, n){
			if(!use[i]){
				ans[zero[0]] = i;
				break;
			}
		}
	}else{
		int j = 0;
		reppp(i, 1, n){
			if(!use[i]){
				ans[zero[j++]] = i;
				use[i] = true;
				if(j > 1) break;
			}
		}
		bool flag = true;
		rep(2){
			int zi = zero[i];
			if(a[zi] == ans[zi] && b[zi] != ans[zi]){
				continue;
			}else if(a[zi] != ans[zi] && b[zi] == ans[zi]){
				continue;
			}else{
				flag = false;
				break;
			}
		}
		if(!flag){
			swap(ans[zero[0]], ans[zero[1]]);
		}
	}
	
	rep(n-1){
		cout << ans[i] << " ";
	}
	cout << ans[n-1];

}

