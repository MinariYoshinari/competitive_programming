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
using std::make_pair;
using std::max;
using std::min;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int dx[2] = {-1,  0};
int dy[2] = { 0, -1};

int n,m,r,k;
Pii center;

ll f(int x, int y){
    return (ll)(min(min(r, n+1-r), min(x, n+1-x)) * min(min(r, m+1-r), min(y, m+1-y)));
}

int is_center(int x, int y){
    int ret = 0;
    if(x == center.first || (n % 2 == 0 && x - 1 == center.first)) ret++;
    if(y == center.second || (m % 2 == 0 && y - 1 == center.second)) ret+=2;
    return ret;
}

int main(){
    scanf("%d %d %d %d", &n, &m, &r, &k);

    ll total = 0;
    priority_queue< pair<ll, Pii> > que;
    center = make_pair((n+1)/2, (m+1)/2);
    vector< vector<int> > used(center.first+1, vector<int>(center.second+1, 0));
    que.push(make_pair(f(center.first, center.second), center));

    while(k > 0){
        auto p = que.top(); que.pop();
        if(used[p.second.first][p.second.second]) continue;
        used[p.second.first][p.second.second] = 1;
        // cout << p.second.first << "," << p.second.second << endl;
        // int prev_k = k;
        switch(is_center(p.second.first, p.second.second)){
            case 3:
                if(n % 2  == 0 && m % 2 == 0){
                    total += min(4, k) * p.first;
                    k -= 4;
                }else if(n % 2 == 0 || m % 2 == 0){
                    total += min(2, k) * p.first;
                    k -= 2;
                }else{
                    total += p.first;
                    k--;
                }
                break;
            case 1:
                if(n % 2  == 0){
                    total += min(4, k) * p.first;
                    k -= 4;
                }else{
                    total += min(2, k) * p.first;
                    k -= 2;
                }
                break;
            case 2:
                if(m % 2  == 0){
                    total += min(4, k) * p.first;
                    k -= 4;
                }else{
                    total += min(2, k) * p.first;
                    k -= 2;
                }
                break;
            case 0:
                total += min(4, k) * p.first;
                k -= 4;
                break;
            default:
                break;
        }
        // cout << p.first << '*' << k << endl;

        rep(2){
            int x = p.second.first+dx[i];
            int y = p.second.second+dy[i];
            if(x <= 0 || y <= 0) continue;
            if(used[x][y] == 0) que.push(make_pair(f(x, y), Pii(x, y)));
        }
    }
    printf("%.10Lf\n", (long double)total / (long double)((n-r+1) * (m-r+1)));
    return 0;
}
