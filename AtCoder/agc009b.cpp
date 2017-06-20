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
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

map< ll, vector<ll> > children;
ll dfs(ll d){
	vector<ll> d_children;
	for(ll child : children[d]){
		d_children.emplace_back(dfs(child));
	}
	if(d_children.size() == 0) return 0;
	else{
		sort(rall(d_children));
		rep((int)d_children.size()){
			d_children[i]+=i+1;
		}
		return *max_element(all(d_children));
	}
}

signed main(){
	int N;
	ll tmp;
	cin >> N;
	rep(N-1){
		cin >> tmp;
		children[tmp].emplace_back(i+2);
	}
	cout << dfs(1);
}
