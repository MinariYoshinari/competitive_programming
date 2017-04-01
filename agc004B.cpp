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

ll ans = 0;
ll N, K;
vector<bool> check(100000, false);
vector<ll> es[100000];
void bfs(vector<ll> es[], ll top, ll depth){
	check[top] = true;
	queue<P> q;
	
	for(ll child : es[top]){
		q.push(make_pair(child, 1));
	}
	while(!q.empty()){
		auto p = q.front(); q.pop();
		check[p.first] = true;
		ll new_depth = p.second+1;
		if(p.second > K){
			cout << p.second << endl;
			ans++;
			new_depth = 2;
		}

		for(ll child: es[p.first]){
			if(!check[child]){
				q.push(make_pair(child, new_depth));
			}
		}
	}
}

signed main(){
	cin >> N >> K;

	rep(N){
		ll t;
		cin >> t;
		es[i].push_back(t-1);
	}
	bfs(es, 0, 0);
	cout << (ans>0?ans+1:0);
}
