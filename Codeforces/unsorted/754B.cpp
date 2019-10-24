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
  char a[4][4];
  rep(4){
	repp(j, 4){
	  scanf("%c", &a[i][j]);	  
	}
	char tmp;
	scanf("%c", &tmp);
  }

  int d[3] = {-1, 0, 1};
  repp(i,4){
	repp(j,4){
	  if(a[i][j] == 'x'){
		if(1<=i && i <= 2){
			repp(k,3){
			  if((j == 0 || j == 3) && k != 1) continue;
			  if((a[i-1][j+d[k]] == 'x' && a[i+1][j-d[k]] == '.') || (a[i+1][j+d[k]] == 'x' && a[i-1][j-d[k]] == '.') ){
				printf("YES");
				return 0;
			  }
			}
		}
		if((j == 1 || j == 2) && ((a[i][j-1] == 'x' && a[i][j+1] == '.') || (a[i][j+1] == 'x' && a[i][j-1] == '.'))){
		  printf("YES");
		  return 0;
		}
 
	  }else if(a[i][j] == '.'){
		if(1<=i && i <= 2){
			repp(k,3){
			  if((j == 0 || j == 3) && k != 1) continue;
			  if(a[i-1][j+d[k]] == 'x' && a[i+1][j-d[k]] == 'x'){
				printf("YES");
				return 0;
			  }
			}
		}
		if((j == 1 || j == 2) && a[i][j-1] == 'x' && a[i][j+1] == 'x'){
		  printf("YES");
		  return 0;
		}
	  }
	}
  }

  printf("NO");
  return 0;
}
