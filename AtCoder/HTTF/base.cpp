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
struct edge{int from, to; ll cost;};

int a[N][N], b[N][N], edge[N][N], fail[N][N];

double time(clock_t start, clock_t end){
    return (double)(end-start)/CLOCKS_PER_SEC;
}

ll calc_points(){
    ll ret = 0LL;
    rep(N){
        repp(j, N) ret += abs(a[i][j] - b[i][j]);
    }
    return 200000000 - ret;
}

void calc_edge(){
    rep(N){
        repp(j,N){
            if(fail[i][j]) edge[i][j] = -50;
            int diff = a[i][j]-b[i][j];
            if(i != 0)   edge[i][j] -= diff - (a[i-1][j] - b[i-1][j]);
            if(i != N-1) edge[i][j] -= diff - (a[i+1][j] - b[i+1][j]);
            if(j != 0)   edge[i][j] -= diff - (a[i][j-1] - b[i][j-1]);
            if(j != N-1) edge[i][j] -= diff - (a[i][j+1] - b[i][j+1]);
        }
    }
}

void print_diff(){
    rep(N){
        repp(j, N) printf("%5d ", b[i][j]-a[i][j]);
        printf("\n");
    }
}

int main(){
    clock_t start = clock();
    rep(N){
        repp(j, N){
            scanf("%d", &a[i][j]);
        }
    }


    vector<Piii> ans(1000), final_ans;
    int m = 0;
    ll prev_point = LLONG_MIN, now_point;
    while(m < 1000 && time(start, clock()) < 5.9){
        // edgeポイントの高いところ
        calc_edge();
        priority_queue<Piii> que;
        reppp(i, 0, N){
            reppp(j, 0, N){
                if(a[i][j] - b[i][j] > 0) que.push(Piii(edge[i][j], Pii(i, j)));
            }
        }
        if(que.empty()) break;
        int pi = que.top().second.first, pj = que.top().second.second;

        int diff = min(N, a[pi][pj] - b[pi][pj]);
        rep(N){
            repp(j, N){
                int dist = abs(i-pi)+abs(j-pj);
                if(dist >= diff) continue;
                b[i][j] += diff-dist;
            }
        }

        now_point = calc_points();
        if(prev_point > now_point){
            fail[pi][pj] = 1;
            rep(N){
                repp(j, N){
                    int dist = abs(i-pi)+abs(j-pj);
                    if(dist >= diff) continue;
                    b[i][j] -= diff-dist;
                }
            }
            continue;
        }
        prev_point = now_point;
        if(m % 10 == 0) cerr << now_point << endl;
        ans[m++] = Piii(diff, Pii(pi, pj));
    }

    cerr << calc_points() << endl;
    printf("%d\n", m);
    rep(m){
        Piii p = ans[i];
        printf("%d %d %d\n", p.second.first, p.second.second, p.first);
    }

}