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
	ll a, b, c, d;
	cin >> a >> b; 
	cin >> c >>d;
	if(a % 2 == 0 && c % 2 == 0 && (b-d) % 2 != 1){
		cout << "-1";
		return 0;
	}
	while(b != d){
		if(b < d){
			b += a;
		}else{
			d += c;
		}
	}
	cout << b;
	return 0;
}
