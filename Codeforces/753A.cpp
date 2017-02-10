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
  int n;
  scanf("%d", &n);

  int k = 1;
  while(k * (k+1) / 2 - 1 < n) k++;
  k--;
  printf("%d\n", k);

  int m = 1;
  while(n > m && m < k){
    printf("%d ", m);
	n -= m;
	m++;
  }
  printf("%d", n);
}
/*
0 1 2 3 4 5 6 7 8 9 10
0 1 1 2 2 2 3 3 3 3 4
0 1 1 3 3 3 6 6 6 6 10
*/
