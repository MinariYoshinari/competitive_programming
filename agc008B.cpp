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
    ll N, K;
	cin >> N >> K;
	vector<ll> a(N);
	rep(N) cin >> a[i];
	ll total = 0;
	rep(K) total += a[i];
    ll max_total = total, min_total = total;
    ll max_i = K-1, min_i = K-1;
	reppp(i, K, N-1){
	    total -= a[i-K];
	    total += a[i];
	    if(total > max_total){
	        max_total = total;
	        max_i = i;
	    }else if(total < min_total){
	        min_total = total;
	        min_i = i;
	    }
	}
	ll ans1 = 0, ans2 = 0;
	rep(N){
	    if(i+(K-1) >= max_i && i <= max_i){
	        ans1 += a[i];
	    }else if(a[i] >= 0){
	        ans1 += a[i];
	    }
	    if(i+(K-1) >= min_i && i <= min_i){
	    }else if(a[i] >= 0){
	        ans2 += a[i];
	    }
	}
	cout << (ans1 > ans2 ? ans1 : ans2);
}
