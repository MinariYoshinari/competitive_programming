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
	vector<ll> a(N), b(N);
	rep(N){
		ll tmp;
		cin >> tmp;
		if(i == 0){
			if(tmp > 0){
				b[0] = tmp;
			}else{
				b[0] = 0;
			}
			a[0] = tmp;
		}else{
			if(tmp > 0){
				b[i] = b[i-1] + tmp;
			}else{
				b[i] = b[i-1];
			}
			a[i] = a[i-1] + tmp;
		}
	}

	ll ans = b[N-1] - b[K-1];
	if(a[K-1] > 0) ans += a[K-1];
	reppp(i, K, N-1){
		ll tmp = b[i-K] + b[N-1] - b[i];
		if(a[i] - a[i-K] > 0) tmp += a[i] - a[i-K];
		if(tmp > ans) {
			ans = tmp;
		}
	}
	cout << (ans>0?ans:0) << endl;
}
