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

signed main(){
  int k, n, m;
  cin >> k;

  repp(kk, k){
	cin >> n;
	
	string users[n];
	repp(nn, n){
	  cin >> users[nn];
	}

	cin >> m;

	string messages[m];
	repp(mm, m){
	  cin >> messages[m];
	}
  }
}
