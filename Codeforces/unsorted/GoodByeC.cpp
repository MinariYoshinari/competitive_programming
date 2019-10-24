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

  int rate = INF;
  int c[n], d[n];
  bool div1 = true;
  rep(n){
	int cc;
	scanf("%d %d", &cc, &d[i]);
	if(i == 0){
	  c[0] = cc;
	}else{
	  c[i] = c[i-1] + cc;
	}
	if(d[i] == 2) div1 = false;
  }
  if(div1){
	printf("Infinity");
	return 0;
  }

  int div2max = d[0] == 2? 0 : -100 * 200000;
  rep(n-1){
	if(d[i+1] == 2 && div2max < c[i]){
	  div2max = c[i];
	}
  }
  rate = 1899 - div2max;
  
  if((rate <= 1899 && d[0] == 1)
	||(rate >= 1900 && d[0] == 2)){
	printf("Impossible");
	return 0;
  }
  
  rep(n-1){
	if(rate + c[i] >= 1900 && d[i+1] != 1){
	  printf("Impossible");
	  return 0;
	}else if(rate + c[i] <= 1899 && d[i+1] != 2){
	  printf("Impossible");
	  return 0;
	}
  }

  printf("%d", rate + c[n-1]);  
  return 0;
}
