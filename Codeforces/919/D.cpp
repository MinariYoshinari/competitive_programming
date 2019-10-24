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
#include<bitset>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int n,m;
vector<int> G[300001];
char s[300001];
int gindeg[300001];

vector<int> topological_sort(){
    set<int> st; // 入次数が0の頂点の番号
    int indeg[n];
    fill(indeg, indeg+n, 0);
    rep(n) for(int to: G[i]) indeg[to]++;
    rep(n){
        gindeg[i] = indeg[i];
        if(indeg[i] == 0) st.insert(i);
    }

    vector<int> ret;
    int used[n];
    fill(used, used+n, 0);
    while(!st.empty()){
        int node = *st.begin();
        st.erase(node);
        ret.push_back(node);
        used[node] = 1;
        for(int next: G[node]){
            indeg[next]--;
            if(!used[next] && indeg[next] == 0) st.insert(next);
        }
    }
    return ret;
}

int main(){
    int from,to, ans = -1;
    scanf("%d %d", &n, &m);
    if(n == 1){
        cout << -1 << endl;
        return 0;
    }
    scanf("%s", s);
    rep(m){
        scanf("%d %d", &from, &to);
        G[from-1].push_back(to-1);
    }
    vector<int> v = topological_sort();
    if((int)v.size() < n){
        cout << -1 << endl;
        return 0;
    }
    int dp[26][n];
    fill(dp[0], dp[26], 0);
    for(char c='a';c<='z';c++){
        int ci = (int)(c-'a');
        rep(n){
            if(gindeg[v[i]] == 0){
                dp[ci][v[i]] = (int)(s[v[i]] == c);
            }
            for(int next: G[v[i]]){
                dp[ci][next] = max(dp[ci][next], dp[ci][v[i]]+(int)(s[next] == c));
            }
        }
        rep(n) ans = max(ans, dp[ci][i]);
    }
    printf("%d\n", ans);
    return 0;

}
