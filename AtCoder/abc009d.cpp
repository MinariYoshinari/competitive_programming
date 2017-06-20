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
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

vector<int> c, a(MAX);
vector<bool> a_flag(MAX, false);
int K, M;

int calc(int i){
	if(i < K || a_flag[i]) return a[i];
	else{
		int ret = c[0] & a[i-1];
		reppp(j, 2, K){
			ret ^= c[j-1] & (a_flag[i-j] ? a[i-j] : calc(i-j));
		}
		a[i] = ret;
		a_flag[i] = true;
		return ret;
	}
}

signed main(){
	cin >> K >> M;
	M--;
	rep(K){
		int tmp;
		cin >> tmp;
		a[i] = tmp;
	}
	rep(K){
		int tmp;
		cin >> tmp;
		c.push_back(tmp);
	}
	cout << calc(M);
}
