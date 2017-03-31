#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<tuple>
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
	int N;
	cin >> N;
	vector<ll> dp(N+1, -1);
	vector<bool> flag(N, true);
	map<ll, ll> mp;
	
	rep(N-1){
		cin >> mp[i+2];
		flag[mp[i+2]] = false;
	}

	reppp(i, 1, N){
		if(flag[i]){
			dp[i] = 0;
		}
	}
	repp(k, N){
		vector<bool> flag_copy(flag);
		reppp(i, 1, N){
			if(flag[i]){
				if(dp[mp[i]] == -1 || dp[mp[i]] < dp[i] + 1){
					dp[mp[i]] = dp[i] + 1;
				}else{
					dp[mp[i]]++;
				}
				flag_copy[i] = false;
				flag_copy[mp[i]] = true;
			}
		}
		swap(flag, flag_copy);
		bool finish = flag[1];
		reppp(j, 2, N){
		    if(flag[j]){
		        finish = false;
		    }
        }
		if(finish) break;
	}
	cout << dp[1];
}
