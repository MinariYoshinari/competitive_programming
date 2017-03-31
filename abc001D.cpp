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
typedef pair<int, int> P;
struct edge{int from, to; ll cost;};

signed main(){
	ll n;
	cin >> n;
	vector<P> a(n);
	rep(n){
		string tmp;
		cin >> tmp;
		int t1 = stoi(tmp.substr(0, 4));
		int t2 = stoi(tmp.substr(5, 4));
		if(t1 % 5 > 0) t1 -= t1 % 5;
		if(t2 % 5 > 0) t2 += t2 % 100 > 56 ? 100 - t2 % 100 : 5 - t2 % 5;
		a[i] = make_pair(t1, t2);
	}
	sort(all(a));
	rep(n){
		printf("%04d-%04d\n", a[i].first, a[i].second);
	}
	printf("\n%04d-", a[0].first);
	int finish_tmp = a[0].second;
	reppp(i, 1, n-1){
		if(a[i-1].second > finish_tmp) finish_tmp = a[i].second;
		if(a[i-1].second < a[i].first && a[i-1].second < a[i].second){
			printf("%04d\n%04d-", finish_tmp, a[i].first);
		}
	}
	if(a[n-1].second > finish_tmp) finish_tmp = a[n-1].second;
	printf("%04d\n", finish_tmp);
}

