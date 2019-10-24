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
#include <bitset>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pll;

class HiddenTreeDiv2 {
    public:
    string isPossible(vector<int> a, vector<int> b) {
        int n = (int)a.size();
        vector< pair<ll, Pll> > v;
        rep(n){
            v.push_back(pair<ll, Pll>((ll)(b[i]-a[i]), Pll((ll)b[i], (ll)a[i])));
        }
        sort(all(v));

        vector<ll> bv;
        ll s = 0;
        rep(n){
            cout << v[i].second.first << " "  << v[i].second.second << endl;
            if(v[i].second.first != v[i].second.second){
                int m = (int)bv.size(), flag = 0;
                if(v[i].second.first <= 5){
                    repp(j, m) cout << bv[j] <<  " ";
                    cout << "*" << endl;
                }
                repp(j, pow(2, m)){
                    bitset<14> bs((unsigned long)j);
                    ll ss = v[i].second.second;
                    repp(k, m){
                        if(bs.test(k)) ss += bv[k];
                    }
                    // if(v[i].second.first == 1308723){
                    //     cout << bs << " " << ss << endl;
                    // }
                    if(ss == v[i].second.first){
                        flag = 1;
                        vector<ll> bv2;
                        repp(k, m){
                            if(!bs.test(k)) bv2.push_back(bv[k]);
                        }
                        swap(bv, bv2);
                        break;
                    }
                }
                if(!flag) return "Impossible";
            }
            bv.push_back(v[i].second.first);
            s += v[i].second.second;
        }
        return "Possible";
    }
};

// CUT begin
ifstream data("HiddenTreeDiv2.sample");

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

bool do_test(vector<int> a, vector<int> b, string __expected) {
    time_t startClock = clock();
    HiddenTreeDiv2 *instance = new HiddenTreeDiv2();
    string __result = instance->isPossible(a, b);
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
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1516800117;
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
        cout << "HiddenTreeDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
