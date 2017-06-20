#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
 
using namespace std;
typedef long long ll;

class Saleswoman {
    public:
    int minMoves(vector<int> pos, vector<int> delta) {
		int ret = 0;
		vector<int> total, dem((int)delta.size());
		total.pb(delta[0]);
		dem[0] = (delta[0] < 0);
		reppp(i, 1, (int)delta.size()){
			total.pb(total[i-1] + delta[i]);
			cout << total[i] << endl;
			if(delta[i] < 0) dem[i] = true;
		}

		vector<int> path;
		while(true){
			auto d  = find(all(dem), true);
			if(d == dem.end()) break;
			*d = false;
			path.pb(d - dem.begin());
			auto p = lower_bound(total.begin() + *max_element(all(path))-1, total.end(), 0);
			path.pb(p - total.begin());
		}
		reppp(i, 1, (int)path.size()-1){
			ret += abs(pos[path[i]] - pos[path[i-1]]);
		}

/*
		auto flag  = find(all(dem), true);
		while(flag != dem.end()){
			for(auto item : total){
				cout << item << endl;
			}
			auto p = lower_bound(total.begin() + (flag - dem.begin()-1),total.end(), 0);
			ret += abs(pos[p - total.begin()] - sw) + abs(pos[p - total.begin()] - pos[flag - dem.begin()]);
			have += *p - delta[flag - dem.begin()];
			cout << p - total.begin() << " " << sw << " " << pos[flag-dem.begin()] << endl;
			cout << ret << endl;
			sw = pos[flag - dem.begin()];
			*flag = false;
			flag = find(all(dem), true);
		}
*/
        return ret;
    }
};

// CUT begin
ifstream data("Saleswoman.sample");

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

bool do_test(vector<int> pos, vector<int> delta, int __expected) {
    time_t startClock = clock();
    Saleswoman *instance = new Saleswoman();
    int __result = instance->minMoves(pos, delta);
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
        vector<int> pos;
        from_stream(pos);
        vector<int> delta;
        from_stream(delta);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pos, delta, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1494156589;
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
        cout << "Saleswoman (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
