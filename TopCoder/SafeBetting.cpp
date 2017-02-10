#include<cstdio>
#include<cstdlib>
#include<cmath>
 
using namespace std;

class SafeBetting {

	public:

	int minRounds(int a, int b, int c) {

	  int bb = b, ans = 0;
	  while(bb < c){
		bb =  2*bb - a;
		ans++;
	  }
	  return ans;

	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arg1 = 20; int Arg2 = 48; int Arg3 = 3; verify_case(0, Arg3, minRounds(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 400; int Arg2 = 560; int Arg3 = 1; verify_case(1, Arg3, minRounds(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 21; int Arg3 = 3; verify_case(2, Arg3, minRounds(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 22; int Arg3 = 4; verify_case(3, Arg3, minRounds(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 17; int Arg1 = 30; int Arg2 = 1000; int Arg3 = 7; verify_case(4, Arg3, minRounds(Arg0, Arg1, Arg2)); }

// END CUT HERE


};



// BEGIN CUT HERE 

signed main() {

	SafeBetting ___test;

	___test.run_test(-1);

}

// END CUT HERE
