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

/*
逆順ソート sort(ALL(vec), greater<ll>());
ペア定義 P pair = make_pair(100, 200);
集合find set.find(item);
小さい順に取り出したい優先度付きキュー
priority_queue<int, vector<int>, greater<int> > que;
配列の最大要素 *std::max_element(ALL(vec))
*/

signed main(){
	int x, y, n;
	scanf("%d %d %d", &y, &x, &n);
	
	if(n == 0){
		printf("%lld\n", (ll)(x-2) * (ll)(y-2));
		return 0;
	}
	
	rep(n){
		int xx, yy;
		scanf("%d %d", &yy, &xx);
		xx--; yy--;
		
		reppp(di, max(1, yy-1), min(yy+1, y-2)){
			reppp(dj, max(1, xx-1), min(xx+1, x-2)){
				a[di][dj]++;
			}
		}
	}
	
	vector<int> ans(10, 0);
	reppp(i, 1, y-2){
		reppp(j, 1, x-2){
			ans[a[i][j]]++;
		}
	}
	
	rep(10){
		printf("%d\n", ans[i]);
	}
}
