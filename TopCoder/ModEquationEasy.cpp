#include<cstdio>
#include<cstdlib>
#include<vector>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
 
using namespace std;
typedef long long ll;

class ModEquationEasy {

	public:

	int count(int n, int K, int v) {
	  ll a[K][K];
	  fill(a[0], a[K], 0);
	  rep(K){
		repp(j, K){
		  a[i][(i*j)%K]++;
		}
	  }

	  int m = 1;
	  ll b[K][K];
	  rep(K){
		repp(j, K){
		  b[i][j] = a[i][j];
		}
	  }
	  
	  while(m < n){		
		ll c[K][K];
		fill(c[0], c[K], 0);
		if(m * 2 > n){
		  rep(K){
			repp(j, K){
			  repp(k, K){
			    c[i][j] += a[i][k] * b[k][j];
			  }
			}
		  }
		  m += 1;
		}else{
		  rep(K){
			repp(j, K){
			  repp(k, K){
			    c[i][j] += b[i][k] * b[k][j];
			  }
			}
		  }
		  m *= 2;
		}

		rep(K){
		  repp(j, K){
			b[i][j] = c[i][j];
		  }
		}
		
	  }
	  
	  return (int)(b[1][v] % MOD);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 0; int Arg3 = 8; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 2; int Arg3 = 4; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 5; int Arg3 = 36; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 100; int Arg2 = 50; int Arg3 = 683036071; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};



// BEGIN CUT HERE 

signed main() {

	ModEquationEasy ___test;

	___test.run_test(-1);

}

// END CUT HERE
