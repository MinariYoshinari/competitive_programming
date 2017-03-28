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
	vector<ll> bb(1000), dd(1000);
	rep(1000) bb[i] = b + a * i;
	rep(1000) dd[i] = d + c * i;
	int i = 0, j = 0;
	while(bb[i] != dd[j] && i < 1000 && j < 1000){
		if(bb[i] < dd[j]){
			i++;
		}else{
			j++;
		}
	}
	if(bb[i] == dd[j]){
		cout << bb[i];
	}else{
		cout << "-1";
	}
	return 0;
}
