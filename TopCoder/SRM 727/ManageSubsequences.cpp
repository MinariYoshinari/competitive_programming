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
#include <climits>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)

using namespace std;

class ManageSubsequences {
    public:
    int minAdded(string S, string A, string B) {
        cout << endl << S << endl << A << endl << B << endl;
        int n = (int)S.length(), m = (int)A.length(), l = (int)B.length();

        vector< vector< vector<int> > > dp(n+1, vector< vector<int> >(m+1, vector<int>(l+1, INT_MAX)));
        dp[0][0][0] = 0;
        rep(n+1){
            repp(j, m+1){
                repp(k, l){
                    if(dp[i][j][k] == INT_MAX) continue;
                    if(i < n){
                        int jj = j+(j<m && S[i] == A[j]);
                        int kk = k+(S[i] == B[k]);
                        if(jj <= m && kk <= l)
                            dp[i+1][jj][kk] = min(dp[i+1][jj][kk], dp[i][j][k]);
                    }
                    if(j < m){
                        int ii = i+(i<n && S[i] == A[j]);
                        int kk = k+(A[j] == B[k]);
                        if(ii <= n && kk <= l)
                            dp[ii][j+1][kk] = min(dp[ii][j+1][kk], dp[i][j][k]+1);
                    }
                }
            }
        }

        int ans = INT_MAX;
        repp(k,l){
                ans = min(ans, dp[n][m][k]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};

// CUT begin
ifstream data("ManageSubsequences.sample");

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

bool do_test(string S, string A, string B, int __expected) {
    time_t startClock = clock();
    ManageSubsequences *instance = new ManageSubsequences();
    int __result = instance->minAdded(S, A, B);
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
        string S;
        from_stream(S);
        string A;
        from_stream(A);
        string B;
        from_stream(B);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, A, B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1515678063;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ManageSubsequences (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
