#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>
 
using namespace std;

class Cross {

	public:

	string exist(vector <string> board) {

	  string ret("Exist");
	  for(int i=1;i<board.size()-1;i++){
		for(int j=1;j<board[i].size()-1;j++){
		  cout << board[i][j] << endl;
		  if(board[i][j] == '.' || board[i-1][j] == '.' || board[i+1][j] == '.' || board[i][j-1] == '.' || board[i][j+1] == '.'){
			continue;
		  }else{
			return ret;
		  }
		}
	  }

	  string ret2("Does not exist");
	  return ret2;

	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".##",
 "###",
 "##."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(0, Arg1, exist(Arg0)); }
	void test_case_1() { string Arr0[] = {".##",
 "###",
 "#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(1, Arg1, exist(Arg0)); }
	void test_case_2() { string Arr0[] = {"######",
 "######",
 "######",
 "######",
 "######",
 "######",
 "######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(2, Arg1, exist(Arg0)); }
	void test_case_3() { string Arr0[] = {".#.#",
 "#.#.",
 ".#.#",
 "#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(3, Arg1, exist(Arg0)); }
	void test_case_4() { string Arr0[] = {".#.#",
 "###.",
 ".###",
 "#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(4, Arg1, exist(Arg0)); }

// END CUT HERE


};



// BEGIN CUT HERE 

signed main() {

	Cross ___test;

	___test.run_test(-1);

}

// END CUT HERE
