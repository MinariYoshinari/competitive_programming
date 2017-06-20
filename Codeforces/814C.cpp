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
	int n, q;
	cin >> n;
	string s;
	cin >> s;
	cin >> q;

	rep(q){
		int qi;
		char c;
		cin >> qi >> c;

		int tail = 1;
		int qq = (s[0] == c ? 0 : 1);
		while(qq < qi && tail < n){
			if(s[tail] != c) qq++;
			tail++;
		}
		while(s[tail] == c && tail < n) tail++;
		int ans = tail;
		//cout << ans << " ";
		reppp(head, 1, n-1){
			if(s[head-1] != c){
				tail++;
				while(s[tail] == c && tail < n) tail++;
				ans = max(tail-head, ans);
			}
			//cout << ans << " ";
		}
		cout << ans << endl;
	}
}

