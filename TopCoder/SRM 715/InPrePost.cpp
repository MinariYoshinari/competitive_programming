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
#define all(c) c.begin(), c.end()
#define pb(x) push_back(x)

using namespace std;

class InPrePost {
    public:
    int leftpost, leftin, leftpre, rightpost, rightin, rightpre;
    bool myisPossible(vector<string> s,vector<int> a1, vector<int> a2, vector<int> a3) {
        vector<int> b1(a1), b2(a2), b3(a3);
        sort(all(b1));
        sort(all(b2));
        sort(all(b3));
        int n = (int)b1.size();
        rep(n){
            if(b1[i] != b2[i] || b1[i] != b3[i]) return false;
        }
        if(b1.size() == 0) return true;
        int leftnum = 0;
        while(a2[leftnum] != a1[0]) leftnum++;
        vector<int> l[3], r[3];
        vector<int> aa[3] = {a1, a2, a3};
        rep(leftnum){
            l[0].pb(aa[leftpre][leftpre == 0 ? 1+i : i]);
            l[1].pb(aa[leftin][leftin == 0 ? 1+i : i]);
            l[2].pb(aa[leftpost][leftpost == 0 ? 1+i : i]);
        }
        rep(n-1-leftnum){
            r[0].pb(aa[rightpre][rightpre == 2 ? leftnum+i : leftnum+1+i]);
            r[1].pb(aa[rightin][rightin == 2 ? leftnum+i : leftnum+1+i]);
            r[2].pb(aa[rightpost][rightpost == 2 ? leftnum+i : leftnum+1+i]);
        }
        return (myisPossible(s, l[0], l[1], l[2]) && myisPossible(s, r[0], r[1], r[2]));
    }

    string isPossible(vector<string> s, vector<int> a1, vector<int> a2, vector<int> a3) {
        rep(6){
            if(i % 2 == 0){
                if(s[i] == "post") leftpost = i/2;
                else if(s[i] == "pre") leftpre = i/2;
                else leftin = i/2;
            }else{
                if(s[i] == "post") rightpost = i/2;
                else if(s[i] == "pre") rightpre = i/2;
                else rightin = i/2;
            }
        }
        if(myisPossible(s, a1, a2, a3)){
            return "Possible";
        }else{
            return "Impossible";
        }
    }
};

// CUT begin
ifstream data("InPrePost.sample");

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

bool do_test(vector<string> s, vector<int> a1, vector<int> a2, vector<int> a3, string __expected) {
    time_t startClock = clock();
    InPrePost *instance = new InPrePost();
    string __result = instance->isPossible(s, a1, a2, a3);
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
        vector<string> s;
        from_stream(s);
        vector<int> a1;
        from_stream(a1);
        vector<int> a2;
        from_stream(a2);
        vector<int> a3;
        from_stream(a3);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, a1, a2, a3, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1498482274;
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
        cout << "InPrePost (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
