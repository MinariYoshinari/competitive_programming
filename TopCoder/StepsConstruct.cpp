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

class StepsConstruct {

	public:

	string construct(vector <string> board, int k) {

	  if(board[0][0] == '#') return "";
	  
	  queue< tuple<int, int, int, string> > que;
	  int n = board.size(), m = board[0].size();
	  bool flag = false;
	  que.push(make_tuple(0, 0, 0, ""));
	  while(!que.empty()){
		tuple<int, int, int, string> t = que.front(); que.pop();
		int i = get<0>(t), j = get<1>(t), c = get<2>(t);
		string s = get<3>(t);

		if(!flag && c > min(n*m, k)){
		  return "";
		}
		
		if(n-1 == i && m-1 == j){
		  if(c == k){
			return s;
		  }else{
			flag = true;
		  }
		  
		}else{
		  if(j < m-1 && board[i][j+1] == '.'){
			que.push(make_tuple(i, j+1, c+1, s+"R"));
		  }
		  
		  if(j > 0 && board[i][j-1] == '.'){
			que.push(make_tuple(i, j-1, c+1, s+"L"));
		  }
		  
		  if(i < n-1 && board[i+1][j] == '.'){
			que.push(make_tuple(i+1, j, c+1, s+"D"));
		  }
		  
		  if(i > 0 && board[i-1][j] == '.'){
			que.push(make_tuple(i-1, j, c+1, s+"U"));
		  }
		}
	  }
	  return "";
	}
	

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arg2 = "DDRR"; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"...",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "DDRRUULLDDRR"; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...#.",
 "..#..",
 ".#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; string Arg2 = ""; verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"..#",
 "#.#",
 "..#",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = ""; verify_case(3, Arg2, construct(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".#...",
 ".#.#.",
 ".#.#.",
 ".#.#.",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; string Arg2 = "DDDDRRUUUURRDDDD"; verify_case(4, Arg2, construct(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"#.", 
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = ""; verify_case(5, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};



// BEGIN CUT HERE 

signed main() {

	StepsConstruct ___test;

	___test.run_test(-1);

}

// END CUT HERE
