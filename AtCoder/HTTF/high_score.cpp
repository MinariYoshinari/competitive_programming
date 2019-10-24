#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
#define N 100
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
typedef pair<int, Pii> Piii;
typedef pair<Pii, Pii> PiiPii;
struct edge{int from, to; ll cost;};

int a[N][N], b[N][N], fail[N][N];
int m;
vector<Piii> ans(1000);
clock_t start;

int in_time(clock_t start, clock_t end){
    return (end-start) <= 5990000;
}

ll calc_points(){
    ll ret = 0LL;
    rep(N) repp(j, N) ret += abs(a[i][j] - b[i][j]);
    return 200000000-ret;
}

int calc_edge(int i, int j){
    int edge;
    if(fail[i][j]) edge = -50;
    else edge = a[i][j]-b[i][j];
    if(i != 0)   edge += (a[i-1][j] - b[i-1][j]);
    if(i != N-1) edge += (a[i+1][j] - b[i+1][j]);
    if(j != 0)   edge += (a[i][j-1] - b[i][j-1]);
    if(j != N-1) edge += (a[i][j+1] - b[i][j+1]);
    return edge;
}

void solve(){
    ll prev_point = LLONG_MIN, now_point;
    while(m < 1000 && in_time(start, clock())){
        // edgeポイントの高いところ
        priority_queue<Piii> que;
        reppp(i, 0, N){
            reppp(j, 0, N){
                que.emplace(calc_edge(i, j) + abs(ans.back().second.first - i) + abs(ans.back().second.second - j), Pii(i, j));
            }
        }
        if(que.empty()) break;

        ll now_point_max = LLONG_MIN;
        Pii max_p;
        int d, max_d, pi, pj;
        repp(z, 50-m%20){
            Pii p = que.top().second;
            pi = p.first, pj = p.second;
            que.pop();

            d = min(N, a[pi][pj] - b[pi][pj]);
            if(d == 0) continue;
            rep(N){
                repp(j, N){
                    b[i][j] += max(0, d-(abs(i-pi)+abs(j-pj)));
                }
            }

            now_point = calc_points();
            if(prev_point > now_point){
                fail[pi][pj] = 1;
            }else if(now_point > now_point_max){
                now_point_max = now_point;
                max_p = p;
                max_d = d;
            }

            rep(N){
                repp(j, N){
                    b[i][j] -= max(0, d-(abs(i-pi)+abs(j-pj)));
                }
            }

            if(que.empty()) break;
        }

        if(now_point_max == LLONG_MIN || now_point_max < prev_point) continue;
        rep(N){
            repp(j, N){
                b[i][j] += max(0, max_d-(abs(i-pi)+abs(j-pj)));
            }
        }
        prev_point = now_point_max;
        // if(m % 10 == 0) cerr << now_point << endl;
        if(d != 0) ans[m++] = Piii(d, Pii(pi, pj));
    }

    // cerr << calc_points() << endl;
}

int main(){
    start = clock();
    rep(N){
        repp(j, N){
            scanf("%d", &a[i][j]);
        }
    }

    solve();
    
    printf("%d\n", m);
    rep(m){
        Piii p = ans[i];
        printf("%d %d %d\n", p.second.first, p.second.second, p.first);
    }
}
// 194654568
