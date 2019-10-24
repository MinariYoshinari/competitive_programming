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

// is_sortedでそーとできてるかチェックできる
// bはそーとする必要がなかった
signed main(){
	int n, k, zero = 0;
	bool check = false;
	cin >> n >> k;
	vector<int> a(n), b(k);
	rep(n) cin >> a[i];
	rep(k) cin >> b[i];
	sort(rall(b));
	int j = 0;
	rep(n){
		if(a[i] == 0){
			if(i > 0 && a[i-1] >= b[j]){
				check = true;
				break;
			}
			a[i] = b[j++];
		}else{
			if((i > 0 && a[i-1] >= a[i])){
				check = true;
				break;
			}
		}
	}
	if(check) cout << "Yes";
	else cout << "No";
}

