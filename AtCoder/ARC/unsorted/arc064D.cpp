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

#define FOR1(n) for(int i=0;i<n;i++)
#define FOR2(j, n) for(int j=0;j<n;j++)
#define FOR3(i, m, n) for(int i=m;i<=n;i++)
#define ALL(c) c.begin(), c.end()
#define SCANF(x) scanf("%lld", &x)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{ll to; long double cost;};
struct point{ll x, y, r;};
vector<point> points;
vector<edge> edges[1002];

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	P s,t;
	cin >> s.first >> s.second >> t.first >> t.second;
	int n;
	cin >> n;
	point tmp = {s.first, s.second, 0};
	points.push_back(tmp);
	tmp = {t.first, t.second, 0};
	points.push_back(tmp);
	FOR1(n){
		ll x, y, r;
		cin >> x >> y >> r;
		tmp = {x, y, r};
		points.push_back(tmp);
	}

	FOR2(i, points.size()){
		point p = points[i];
		FOR2(j, points.size()){
			point q = points[j];
			if(p.x != q.x || p.y != q.y){
				long double distance = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y)) - p.r - q.r;
				edge e = {j, max((long double)0.0, distance)};
				edges[i].push_back(e);
			}
		}
	}

	long double d[points.size()];

	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d+(points.size()+2), INF);
	d[0] = 0;
	que.push(P(0, 0));

	while(!que.empty()){
		P p = que.top(); que.pop();
		ll v = p.second;
		if(d[v] < p.first) continue;
		FOR1(edges[v].size()){
			edge e = edges[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	printf("%.12Lf", d[1]);
}
