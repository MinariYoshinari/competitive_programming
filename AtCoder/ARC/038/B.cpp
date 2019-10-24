#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::priority_queue;
using std::stack;
using std::map;
using std::pair;
using std::string;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int h,w;
int game[102][102];
int grundy[101][101];

int dfs(int y, int x){
    if(y > h || x > w || game[y][x]) return -1;
    if(grundy[y][x] != -1) return grundy[y][x];
    int next[3], ret = 0, flag = 1;
    next[0] = dfs(y+1, x);
    next[1] = dfs(y, x+1);
    next[2] = dfs(y+1, x+1);
    while(flag){
        flag = 0;
        rep(3){
            if(ret == next[i]){
                ret++;
                flag = 1;
                break;
            }
        }
    }
    grundy[y][x] = ret;
    return ret;
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> h >> w;
    rep(w+2){
        game[0][i] = 1;
        game[h+1][i] = 1;
    }
    rep(h+2){
        game[i][0] = 1;
        game[i][w+1] = 1;
    }
    reppp(i, 1, h+1){
        cin >> s;
        reppp(j, 1, w+1) if(s[j-1] == '#') game[i][j] = 1;
    }

    reppp(i, 1, h+1){
        reppp(j, 1, w+1){
            if(game[i+1][j] & game[i][j+1] & game[i+1][j+1]){
                grundy[i][j] = 0;
            }else{
                grundy[i][j] = -1;
            }
        }
    }

    if(dfs(1, 1) == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }

}
