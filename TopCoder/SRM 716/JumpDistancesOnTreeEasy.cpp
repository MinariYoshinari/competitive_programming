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
#include<numeric>

#include <ctime>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
 
using namespace std;
typedef long long ll;

class JumpDistancesOnTreeEasy {
    public:
        vector<int> tree[50];
        vector<int> depthes;
        vector<int> radiuses;

    void dfs(int node, int depth, vector<int> use){
        use[node] = 1;
        depthes[node] = depth;
        int flag = 0;
        for(int next: tree[node]){
            if(!use[next]){
                flag = 1;
                dfs(next, depth+1, use);
            }
        }
        if(!flag) radiuses.pb(depth);
    }

    string isPossible(vector<int> p, vector<int> S) {
        int n = (int)p.size() + 1;
        rep(n){
            tree[i+1].pb(p[i]);
            tree[p[i]].pb(i+1);
            depthes.pb(0);
        }
        dfs(0, 0, vector<int>(n, 0));
        sort(rall(radiuses));
        rep(n){
            cout << depthes[i] <<  " ";
        }
        cout << endl;
        cout << radiuses[0] <<  " " << radiuses[1] << endl;

        vector<int> need;
        int flag;
        for(int s: S){
            cout << s << endl;
            if(s <= radiuses[0]) continue;
            else if(s > radiuses[0] + radiuses[1]){
                return "Impossible";
            }else{
                flag = 0;
                reppp(i, radiuses[0], s-radiuses[1]){
                    if(find(all(S), i) != S.end()){
                        flag = 1;
                        break;
                    }
                }
                if(!flag) return "Impossible";
            }
        }

        return "Possible";
    }
};

// CUT begin
ifstream data("JumpDistancesOnTreeEasy.sample");

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

bool do_test(vector<int> p, vector<int> S, string __expected) {
    time_t startClock = clock();
    JumpDistancesOnTreeEasy *instance = new JumpDistancesOnTreeEasy();
    string __result = instance->isPossible(p, S);
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
        vector<int> p;
        from_stream(p);
        vector<int> S;
        from_stream(S);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, S, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503488107;
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
        cout << "JumpDistancesOnTreeEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
