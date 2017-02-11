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

class PalindromicSubseq2 {

	public:

	int solve(string s) {
	  int n = s.size();
	  ll dp[n][n];
	  fill(dp[0], dp[n], 0);
	  dp[0][n-1] = 1 + ((s[0] == s[n-1])? 1 : 0);
	  for(int j=n-2;j>0;j--){
		dp[0][j] = dp[0][j+1] + ((s[0] == s[j])? 1 : 0);
	  }
	  reppp(i, 1, n-2){
		dp[i][n-1] = dp[i-1][n-1] + ((s[i] == s[n-1])? 1 : 0);
		for(int j=n-2;j>i;j--){
		  dp[i][j] = dp[i-1][j] + dp[i][j+1] - ((s[i] != s[j])? dp[i-1][j+1] : 0);
		  if(dp[i][j] >= MOD) dp[i][j] %= MOD;
		}
	  }
	  
	  ll ans = 1;
	  reppp(i, 1, n-2){
		ans ^= ((i+1) * dp[i-1][i+1]) % MOD;
	  }
	  ans ^= n * 1;
	  return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "axbcba"; int Arg1 = 31; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "eeeee"; int Arg1 = 14; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "tcoct"; int Arg1 = 4; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arg0 = "zyzyzzzzxzyz"; int Arg1 = 221; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 1044407608; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE


};



// BEGIN CUT HERE 

signed main() {

	PalindromicSubseq2 ___test;

	___test.run_test(-1);

}

// END CUT HERE
