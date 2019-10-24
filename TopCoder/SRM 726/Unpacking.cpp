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

using namespace std;

class Unpacking {
    public:
    int solve(vector<int> v, vector<int> cost, int K){
        int n = (int)v.size(), limit = 0;
        vector< vector<int> > dp(n+1, vector<int>(K+1, INT_MAX));
        dp[0][0] = 0;
        rep(n){
            limit = min(limit+v[i], K);
            repp(j, limit+1){
                if(dp[i][j] == INT_MAX) continue;
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                dp[i+1][min(K, j+v[i])] = min(dp[i+1][min(K, j+v[i])], dp[i][j] + cost[i]);
            }
        }
        return dp[n][K];
    }

    int getcost(vector<int> a, vector<int> b, vector<int> cost, int K) {
        int n = (int)a.size();
        vector<int> v(n);
        rep(n){
            v[i] = a[i]+b[i];
            a[i]--; b[i]--;
        }
        int ans = min(solve(v, cost, K*2-1), min(solve(a, cost, K), solve(b, cost, K)));
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};

// CUT begin
ifstream data("Unpacking.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(vector<int> a, vector<int> b, vector<int> cost, int K, int __expected) {
    time_t startClock = clock();
    Unpacking *instance = new Unpacking();
    int __result = instance->getcost(a, b, cost, K);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        vector<int> cost;
        from_stream(cost);
        int K;
        from_stream(K);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, b, cost, K, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1514297178;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Unpacking (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
