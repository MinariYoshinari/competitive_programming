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
#include <numeric>
#include <cassert>


#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()

using namespace std;
typedef long long ll;
struct edge{int to; ll cap; int rev;};

class ScoresSequence {
    public:
    vector<edge> G[300];
    int iter[300], level[300];

    void add_edge(int from, int to, ll cap){
        /*
            ある点vに対する辺の集合はvectorで管理されているので，
            そのvectorの中の何番目の辺に対応しているかを記憶する→rev
        */
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size()-1});
    }

    void bfs(int s){
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int i=0;i<G[v].size();i++){
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    ll dfs(int v, int t, ll f){
        if(v == t) return f;
        for(int &i=iter[v];i<(int)G[v].size();i++){
            edge &e = G[v][i]; //eの中身を書き換えたいのでポインタを使用
            if(level[v] < level[e.to] && e.cap > 0){
                ll d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll dinic(int s, int t){
        ll max_flow = 0;
        while(true){
            bfs(s);
            if(level[t] < 0) return max_flow;
            memset(iter, 0, sizeof(iter));
            ll f;
            while((f = dfs(s, t, INT_MAX)) > 0){
                max_flow += f;
            }
        }

        return max_flow;
    }

    int count(vector<int> s) {
        int n = (int)s.size();
        rep(n){
            add_edge(0, i+1, s[i]);
            add_edge(n+i+1, 2*n+1, n-1-s[i]);
            repp(j, i){
                if(i == j) continue;
                add_edge(j+1, n+i+1, 1);
            }
        }
        assert(dinic(0, 2*n+1) == (ll)accumulate(all(s), 0));

        int graph[n+2][n+2], graph2[n+2][n+2];
        fill(graph[0], graph[n+2], 0);
        fill(graph2[0], graph2[n+2], 0);
        reppp(i, 1, n){
            graph[i-1][i-1] = 1;
            graph2[i-1][i-1] = 1;
            for(edge e:G[i]){
                if(n < e.to && e.to <= 2*n){
                    if(e.cap == 1) graph[i-1][e.to-n-1] = 1;
                    else graph2[i-1][e.to-n-1] = 1;
                }
            }
        }

        repp(k, n){
            repp(i, n){
                repp(j, n){
                    graph[i][j] |= graph[i][k]&graph[k][j];
                    graph2[i][j] |= graph2[i][k]&graph2[k][j];
                }
            }
        }
        
        int ret = 0, ret2 = 0;
        repp(i, n){
            repp(j, n){
                ret += graph[i][j];
                ret2 += graph2[i][j];
            }
        }

        return max(ret, ret2);
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