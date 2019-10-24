#include <cstdio>
#include <cmath>
#include <climits>
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
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9

using namespace std;

class ManageSubsequences {
    public:

    int is_substring(string S, string A){
        int ns = (int)S.length(), na = (int)A.length();
        int i = 0, j = 0;
        while(i < ns && j < na){
            if(S[i] == A[j]) j++;
            i++;
        }
        return j == na;
    }

    int minAdded(string S, string A, string B) {
        cout << endl;
        if(is_substring(S, B) || is_substring(A, B)) return -1;

        int ns = (int)S.length(), na = (int)A.length();
        int ret = na;
        int dp[ns+1][na+1][nb+1];
        dp[0][0][0] = 0;
        reppp(j, 1, na+1){
            dp[0][j][0] = j;
            reppp(k, 1, nb+1){
                if(is_substring(A.substr(0, j), B.substr(0, k)){
                    dp[0][j][k] = -1;
                }else{
                    dp[0][j][k] = j;
                }
            }
        }
        reppp(i, 1, ns+1){
            reppp(j, 1, na+1){
                if(S[i-1] == A[j-1])
                    dp[i][j][0] = dp[i-1][j-1][0] + 1;
                else
                    dp[i][j][0] = dp[i-1][j-1][0];
                reppp(k, 1, nb+1){
                    
                }
            }
        }
        /*
        rep(ns){
            int ii = i, j = 0;
            vector<int> match(na);
            while(ii < ns && j < na && S[ii] == A[j]){
                if(S[ii] == A[j]){
                    match[j] = ii;
                    j++;
                }
                ii++;
            }
            repp(k, j){
                string C = S.substr(0, match[k]+1) + A.substr(k+1, na-k) + S.substr(match[k]+1, ns-match[k]-1);
                if(!is_substring(C, B)){
                    cout << C << " " << k+1 << endl;
                    ret = min(ret, na-k-1);
                }
            }
        }
        return ret;
        */
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
        int T = time(NULL) - 1515637436;
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
