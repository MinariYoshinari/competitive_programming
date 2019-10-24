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
#define ll long long

using namespace std;

class DerangementsDiv2 {
    public:
        ll fact[51], rfact[51];

    ll comb(ll n, ll r){
        return (((fact[n] * rfact[r]) % MOD) * rfact[n-r]) % MOD;
    }

    void make_comb(){
        fact[0] = fact[1] = 1;
        rfact[0] = rfact[1] = 1;
        reppp(i, 2, 50){
            fact[i] = (fact[i-1] * (ll)i) % MOD;
            rfact[i] = 1;
            ll k = MOD-2;
            ll a = fact[i];
            while(k > 0){
                if(k & 1){
                    rfact[i] *= a;
                    rfact[i] %= MOD;
                }
                a *= a;
                a %= MOD;
                k  >>= 1;
            }
        }
    }

    int count(int n, int m) {
        make_comb();
        ll ret = 0;
        ll sign = (m%2 == 1)?-1:1;
        for(int i=m; i>=0; i--){
            ret += (sign * comb(m, i) * fact[n+m-i]) % MOD;
            sign *= -1;
        }


        return ret;
    }
};

// CUT begin
ifstream data("DerangementsDiv2.sample");

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

bool do_test(int n, int m, int __expected) {
    time_t startClock = clock();
    DerangementsDiv2 *instance = new DerangementsDiv2();
    int __result = instance->count(n, m);
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
        int n;
        from_stream(n);
        int m;
        from_stream(m);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503399848;
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
        cout << "DerangementsDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
