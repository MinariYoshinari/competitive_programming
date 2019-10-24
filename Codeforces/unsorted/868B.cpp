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
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    double h, m, s, start, goal;
    cin >> h >> m >> s >> start >> goal;
    if(h == 12) h = 0;
    start *= 30;
    goal  *= 30;
    if(start > goal) swap(start, goal);

    double hands[3];
    hands[0] = h * 30 + m * 0.5 + s * 0.5 / 60;
    hands[1] = m * 6 + s * 0.5 / 60;
    hands[2] = s * 6;

    //cout << start << " " << goal << endl;
    //cout << hands[0] <<  " " << hands[1] <<  " " << hands[2] << endl;
    int flag[2] = {0, 0};
    rep(3){
        if(start < hands[i] && hands[i] < goal){
            flag[0] = 1;
        }else if(hands[i] < start || goal < hands[i]){
            flag[1] = 1;
        }
    }
    //cout << flag[0] << flag[1] << endl;
    if(flag[0] && flag[1]){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;

}
