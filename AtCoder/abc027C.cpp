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
	ll N, d = 0;
	cin >> N;
	for(ll n = N; n>0; n /= 2) d++;
	bool takahashi = true;
	ll n = 1;
	while(n <= N){
		if(d % 2){
			if(takahashi){
				n = 2*n+1;
			}else{
				n = 2*n;
			}
		}else{
			if(takahashi){
				n = 2*n;
			}else{
				n = 2*n+1;
			}
		}
		takahashi ^= true;
	}
	if(takahashi){
		cout << "Takahashi" << endl;
	}else{
		cout << "Aoki" << endl;
	}
}
