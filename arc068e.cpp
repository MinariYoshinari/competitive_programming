#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
 
using namespace std;

signed main(){
	int n, m;
	cin >> n >> m;
	vector<int> ans(m+1, 0);
	ans[1] = n;
	int l, r;
	rep(n){
	  scanf("%d %d", &l, &r);
		reppp(mi, 2, r){
		  if((l-1) / mi != r / mi){
				ans[mi]++;	
		  }
		}
	}
	reppp(i, 1, m){
	  printf("%d"ans[i] << endl;
	}
}
