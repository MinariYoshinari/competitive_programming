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
#define MAX 10000
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

int par[MAX];  //親
int depth[MAX]; //深さ
int size[MAX]; //その木の要素数

//初期化
void init(int n){
    rep(n){
        par[i] = i;
        depth[i] = 0;
		size[i] = 1;
    }
}

//根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

//xとyの属する集合の併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    if(depth[x] < depth[y]){
        par[x] = y;
		size[y] += size[x];
    }else{
        par[y] = x;
		size[x] += size[y];
        if(depth[x] == depth[y]) depth[x]++;
    }
}

//同じ集合に属するか否か
bool same(int x, int y){
    return find(x) == find(y);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
}
