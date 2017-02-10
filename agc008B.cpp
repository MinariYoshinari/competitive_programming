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
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	ll score = 0;
	int n, k;
	ll a[n], sum[n-k+1];
	fill(sum, sum+(n-k+1), 0);
	cin >> n >> k;
	rep(n){
		cin >> a[i];
		for(int j=i;j>max(0, i-k);j--){
			sum[j] += a[i];
		}
	}
	ll* maxe = max_element(sum, sum+(n-k+1));
	ll* mine = min_element(sum, sum+(n-k+1));
	ll k_i;
	if(*maxe + *mine > 0){
		score = *maxe;
		k_i = maxe - sum;
	}else{
		k_i = mine - sum;
	}
	rep(k_i){
		if(a[i] > 0) score += a[i];
	}
	reppp(i, k_i+k, n-1){
		if(a[i] > 0) score += a[i];
	}
	
	cout << score;
}
