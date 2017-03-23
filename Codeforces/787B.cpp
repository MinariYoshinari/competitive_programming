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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};
int N;
 
int main(){
	ll n,m;
	cin >> n >> m; 
	bool ans = false;
	if(n==1){
		cout << "NO";
		return 0;
	}
	rep(m){
		ll k;
		cin >> k;
		bool flag = true;
		map<ll, bool> mp;
		repp(j,k){
			ll tmp;
			cin >> tmp;
			if(mp[-tmp]){
				flag = false;
				break;
			}else{
				mp[tmp] = true;
			}
		}
		if(flag || k == 1){
			ans = true;
			break;
		}
	}
	cout << (ans ? "YES" : "NO");
	return 0;
}
