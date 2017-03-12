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

class Softmatchd2 {

	public:

	bool match(char c, char pc){
	  int num = (int)pc - (int)'0';
	  switch(c){
	    case 'a':
		  return num <= 1;
		case 'A':
		  return num >= 2;
		case 'b':
		  return num % 2 == 0;
		case 'B':
		  return num % 2 == 1;
		default:
		  break;
		}
		return false;
	}

	int count(string S, string pattern) {

	  int ns = (int)S.size(), np = (int)pattern.size();
	  vector<P> point(ns-np+1);
	  bool is_matched[ns-np+1][ns];
	  rep(ns-np+1){
		int p = 0;
		repp(j, np){
		  if(match(S[i+j], pattern[j])){
			is_matched[i][i+j] = true;
			p++;
		  }else{
			is_matched[i][i+j] = false;
		  }
		}
		point[i] = make_pair(p, i);
	  }

	  int ans = 0;
	  sort(all(point));
	  vector<bool> comfirm(ns, false);
	  rep(ns-np+1){
		int ii = point[ns-1-i].second;
		bool flag = true;
		repp(j, np){
		  if(!is_matched[ii][ii+j]){
			if(comfirm[ii+j]){
			  flag = false;
			  break;
			}else{
			  comfirm[ii+j] = true;
			  repp(k, ns-np+1){
				is_matched[k][ii+j] ^= true;
			  }
			}
		  }else{
			comfirm[ii+j] = true;
		  }
		}
		if(flag) ans++;
	  }
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; string Arg1 = "13"; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abbaa"; string Arg1 = "123"; int Arg2 = 2; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "1230"; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ababbaaba"; string Arg1 = "0311"; int Arg2 = 3; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aabbbabbbb"; string Arg1 = "332233"; int Arg2 = 2; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaabbbababababababaaabaa"; string Arg1 = "02232"; int Arg2 = 9; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};



// BEGIN CUT HERE 

signed main() {

	Softmatchd2 ___test;

	___test.run_test(-1);

}

// END CUT HERE
