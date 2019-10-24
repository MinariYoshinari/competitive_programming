#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define MOD 1000000007

using namespace std;

class InterleavingParenthesisDiv2 {
    public:
    
    int countWays(string s1, string s2) {
        int n1 = (int)s1.length();
        int n2 = (int)s2.length();
        vector< vector<int> > dp(n1+1, vector<int>(n2+1, 0)), p(n1+1, vector<int>(n2+1, 0));
        dp[0][0] = 1;
        reppp(i, 1, n1){
            if(s1[i-1] == '(') p[i][0] = p[i-1][0] + 1;
            else p[i][0] = p[i-1][0] - 1;
            if(p[i][0] >= 0 && dp[i-1][0] == 1) dp[i][0] = 1;
        }
        reppp(j, 1, n2){
            if(s2[j-1] == '(') p[0][j] = p[0][j-1] + 1;
            else p[0][j] = p[0][j-1] - 1;
            if(p[0][j] >= 0 && dp[0][j-1] == 1) dp[0][j] = 1;
        }
        reppp(i, 1, n1){
            reppp(j, 1, n2){
                if(s1[i-1] == '('){
                    p[i][j] = p[i-1][j] + 1;
                }else{
                    p[i][j] = p[i-1][j] - 1;
                }
                if(p[i][j] >= 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    if(dp[i][j] >= MOD) dp[i][j] -= MOD;
                }
            }
        }
        return dp[n1][n2];
    }
};

// CUT begin
ifstream data("InterleavingParenthesisDiv2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string s1, string s2, int __expected) {
    time_t startClock = clock();
    InterleavingParenthesisDiv2 *instance = new InterleavingParenthesisDiv2();
    int __result = instance->countWays(s1, s2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string s1;
        from_stream(s1);
        string s2;
        from_stream(s2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s1, s2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1502617455;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "InterleavingParenthesisDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
