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

set<int> G[2001];

void search(int node){
    printf("now: %d\n", node);
    int ans;
    if((int)G[node].size() == 2){
        int a = *G[node].begin(), b = *(++G[node].begin());
        printf("? %d %d", a, b);
        scanf("%d", &ans);
        if(ans == 0){
            printf("! %d", node);
            fflush(stdout);
        }else if(ans == a){
            G[a].erase(node);
            search(a);
        }else{
            G[b].erase(node);
            search(b);
        }
        fflush(stdout);
    }else if((int)G[node].size() == 1){
        int a = *G[node].begin();
        printf("? %d %d", node, a);
        scanf("%d", &ans);
        if(ans == a){
            G[a].erase(node);
            search(a);
        }else{
            printf("! %d", node);
            fflush(stdout);
        }
    }else{
        printf("! %d", node);
        fflush(stdout);
    }
    
}

int main(){
    int n,q,a,b;
    scanf("%d %d", &n, &q);
    rep(n-1){
        scanf("%d %d", &a, &b);
        G[a].insert(b);
        G[b].insert(a);
    }
    search(1);
}
