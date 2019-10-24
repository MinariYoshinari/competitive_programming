#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <climits>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int inf = ~0U >> 1;
const ll INF = ~0ULL >> 1;
 
int G[200][200], in[200], out[200];
int n; 
 
class ScoresSequence
{
public:
    int count(vector <int> s)
    {
        n = s.size();
        sort(s.begin(), s.end(), greater<int>());
        for (int i = 0; i < n; ++i) {
            in[i] = n - 1 - s[i];
            out[i] = s[i];
            for (int j = 0; j < n; ++j) 
                G[i][j] = false;
            G[i][i] = true;
        }
        for (int i = 0; i < n; ++i) {
            while (out[i]--) {
                int j = -1;
                for (int k = 0; k < n; ++k) if (i != k && !G[i][k] && (j == -1 || in[k] >= in[j]))
                        j = k;
                G[i][j] = true;
                in[j]--;
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                printf("%2d", G[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    G[i][j] |= G[i][k] & G[k][j];
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                printf("%2d", G[i][j]);
            }
            printf("\n");
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                if (G[i][j]) ++cnt;
        return cnt;
         
    }
 
};

// CUT begin
ifstream data("ScoresSequence.sample");

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

bool do_test(vector<int> s, int __expected) {
    time_t startClock = clock();
    ScoresSequence *instance = new ScoresSequence();
    int __result = instance->count(s);
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
        vector<int> s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1517064359;
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
        cout << "ScoresSequence (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end