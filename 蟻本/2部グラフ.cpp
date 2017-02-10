#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

#define INT unsigned long long int
#define FOR1(n) for(int i=0;i<n;i++)
#define FOR2(j, n) for(int j=0;j<n;j++)
#define FOR3(i, m, n) for(int i=m;i<=n;i++)
#define PINT(d) printf("%d\n", d);
#define PDOUBLE(lf) printf("%lf\n", lf);
#define PSTR(s) printf("%s\n", s);
#define ALL(c) c.begin(), c.end()
#define MOD 1000000007
#define MAX_N 1000

using namespace std;

vector<int> g[MAX_N];
int color[MAX_N] = {};

bool bfs(int i, int c){
    cout << i << " " << c << endl;
    color[i] = c;
    bool ret = true;
    FOR2(j, g[i].end() - g[i].begin()){
        if(color[g[i][j]] == 0){
            ret =  ret & bfs(g[i][j], -c);
        }else if(color[g[i][j]] == c){
            ret = false;
        }
    }
    return ret;
}

main(){
    int from, to;
    int n;
    scanf("%d", &n);
    while(scanf("%d %d", &from, &to) == 2){
        if(from < to){
            g[from].push_back(to);
        }else{
            g[to].push_back(from);
        }
    }
    string s = bfs(0, 1) ? "Yes" : "No";
    cout << s;
}
